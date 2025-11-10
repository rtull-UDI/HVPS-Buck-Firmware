/*
 * File:    main.c
 * Target:  dsPIC33 (MCC-generated project)
 * Toolchain: XC16
 * Brief:   HVPS Buck firmware ? formatting/cleanliness pass with non-functional refactors
 *
 * Assumptions (please adjust to your actual MCC config):
 *  - TMR1 tick rate (TMR1_HZ) defaults to 1 kHz (1 ms period). If your TMR1 differs,
 *    set TMR1_HZ accordingly so debounce/soft-start timing remains correct.
 *  - printf is available over your UART/CDC console. Gate with DEBUG to avoid runtime cost.
 */

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/timer/tmr1.h"
#include "mcc_generated_files/timer/timer_interface.h"
#include "mcc_generated_files/timer/delay.h"
#include "mcc_generated_files/pwm_hs/pwm.h"
#include "mcc_generated_files/adc/adc1.h"
#include "mcc_generated_files/input_capture/input_capture_interface.h"
#include "mcc_generated_files/input_capture/sccp1.h"
#include "mcc_generated_files/input_capture/sccp2.h"

#include "VCOMP.h"
#include "npnz16b.h"

// -----------------------------------------------------------------------------
// Global compile-time configuration & helpers
// -----------------------------------------------------------------------------

#ifndef TMR1_HZ
#define TMR1_HZ                (1000U)  // ASSUMPTION: 1 kHz tick (1 ms)
#endif

#define TICKS_FROM_MS(ms)      ((uint16_t)((uint32_t)(ms) * (uint32_t)TMR1_HZ / 1000U))
#define MS_FROM_TICKS(t)       ((uint32_t)(t) * 1000UL / (uint32_t)TMR1_HZ)

#ifndef DEBUG
#define DEBUG 1              // uncomment for console prints
#endif

#define CLAMP(x, lo, hi)       ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))

// -----------------------------------------------------------------------------
// ADC & scaling configuration
// -----------------------------------------------------------------------------

#define ADC_MAX_COUNT          (4095U)
#define VREF_MV                (3300U)   // Reference voltage in millivolts

// Voltage divider resistors (ohms)
#define VIN_R1_OHM             (99000U)  // Upper resistor
#define VIN_R2_OHM             (1000U)   // Lower resistor

#define VOUT_R1_OHM            (196200U) // Upper resistor
#define VOUT_R2_OHM            (3195U) // Lower resistor

// Timing (expressed in milliseconds, converted to TMR1 ticks)
#define LED_BLINK_MS           (500U)
#define VIN_ON_DEBOUNCE_MS     (2000U)   // Require VIN above threshold for this long before SS
#define SOFT_START_STEP_MS     (2U)      // Ref update interval

// Soft-start ramp step (in ADC counts of Vout reference)
#define VBUCK_RAMP_STEP        ((uint32_t)1U)

// Millivolt setpoints (runtime-tweakable; keep as variables if adjusted elsewhere)
static uint32_t VIN_TH_ON_MV = 210000U;
static uint32_t VIN_TH_OFF_MV = 205000U;
static uint32_t VBUCK_REF_MV = 180000U;

// Integer scale factors (×100 to preserve two decimals)
static int64_t VIN_SCALE_X100 = 0;
static int64_t VOUT_SCALE_X100 = 0;

// ADC threshold equivalents (counts)
static uint32_t VIN_TH_ON_ADC = 0;
static uint32_t VIN_TH_OFF_ADC = 0;
static uint32_t VBUCK_REF_ADC = 0;

// Raw ADC samples (updated in ADC callback)
static volatile uint16_t adc_vin_raw = 0;
static volatile uint16_t adc_vout_raw = 0;

// Debounced/latched copies used by main loop
static volatile uint16_t adc_vin = 0;
static volatile uint16_t adc_vout = 0;

// Computed real voltages in millivolts
static volatile uint32_t vin_mv = 0;
static volatile uint32_t vout_mv = 0;

// Control reference (in ADC counts), adjusted by soft-start state machine
static volatile int ref_vbuck = 0;

// -----------------------------------------------------------------------------
// Simple state machine for startup/soft-start
// -----------------------------------------------------------------------------

typedef enum {
    FSM_IDLE = 0,
    FSM_SOFT_START
} fsm_state_t;

static volatile fsm_state_t fsm_state = FSM_IDLE;
static volatile uint16_t led_tmr_ticks = 0; // heartbeat
static volatile uint16_t start_tmr_ticks = 0; // VIN debounce timer
static volatile uint16_t ss_step_tmr_ticks = 0; // soft-start step timer

// -----------------------------------------------------------------------------
// FET temperature monitoring via input capture (duty extraction)
// -----------------------------------------------------------------------------

// ===== Temperature PWM capture (LMG3522 TEMP pin) =====
// Datasheet mapping (LMG352xR030, Rev B, Jan 2025):
// TJ[°C] = 162.3 * D + 20.1, where D = duty (0..1), fTEMP ~ 9 kHz.
// Duty typical: ~3% @ 25°C to ~82% @ 150°C. OT fault drives TEMP = HIGH.  (TI)
#define TEMP_PWM_PRINT_MS   200U  // UART print period
#define TEMP_IIR_ALPHA_NUM  1U    // IIR alpha = 1/8 (light smoothing)
#define TEMP_IIR_ALPHA_DEN  8U

typedef struct {
    // Raw timestamps captured by ISRs (no math in ISR)
    volatile uint32_t rise_prev_ts;   // previous rising edge timestamp
    volatile uint32_t rise_curr_ts;   // latest rising edge timestamp
    volatile uint32_t fall_ts;        // latest falling edge timestamp

    // Edge flags set by ISRs, consumed in main context
    volatile uint8_t  new_rise;
    volatile uint8_t  new_fall;
    volatile uint8_t  overflow;       // set if either IC overflowed

    // Processed/filtered results (updated in main)
    volatile uint16_t duty_q15;       // filtered duty in Q15
    volatile uint8_t  valid;          // becomes 1 after first full cycle processed
} temp_pwm_t;

static temp_pwm_t fet_temp_top = {0}; // TEMP pin routed to SCCP1 (rise) + SCCP2 (fall)

// Millisecond tick from TMR1 ISR
static volatile uint32_t g_ms = 0;

// Convert Q15 duty to degrees C using TJ = 162.3*D + 20.1
// D = duty_q15 / 32768.  We'll do fixed-point: T = 162.3*(dq15/32768) + 20.1

static inline float temp_q15_to_celsius(uint16_t duty_q15) {
    float D = (float) duty_q15 / 32768.0f;
    return (162.3f * D) + 20.1f;
}

// -----------------------------------------------------------------------------
// Forward declarations
// -----------------------------------------------------------------------------

static void ScaleCalculate(void);
static void VoltageReadout(void);
static void TMR1_INT(void);
static void FET_TOP_Rise_Handler(void);
static void FET_TOP_Fall_Handler(void);
static uint16_t VCOMP_ControllerInitialize(void);

// -----------------------------------------------------------------------------
// Timer1 callback ? heartbeat, state machine, and soft-start
// -----------------------------------------------------------------------------

static void TMR1_INT(void) {
    g_ms++;

    // Heartbeat on LD2/LD3
    if (++led_tmr_ticks >= TICKS_FROM_MS(LED_BLINK_MS)) {
        led_tmr_ticks = 0U;
        LD2_Toggle();
        LD3_Toggle();
    }

    switch (fsm_state) {
        case FSM_IDLE:
            ref_vbuck = 0; // ensure PWM demand is zero

            // Debounce VIN above ON threshold
            if (adc_vin <= VIN_TH_ON_ADC) {
                start_tmr_ticks = 0U;
            } else {
                if (start_tmr_ticks < TICKS_FROM_MS(VIN_ON_DEBOUNCE_MS)) {
                    start_tmr_ticks++;
                }
                if (start_tmr_ticks >= TICKS_FROM_MS(VIN_ON_DEBOUNCE_MS)) {
                    fsm_state = FSM_SOFT_START;
                    ss_step_tmr_ticks = 0U; // start soft-start pacing
                }
            }
            break;

        case FSM_SOFT_START:
            // Pace soft-start by time, not by arbitrary divider
            if (ss_step_tmr_ticks < TICKS_FROM_MS(SOFT_START_STEP_MS)) {
                ss_step_tmr_ticks++;
            } else {
                ss_step_tmr_ticks = 0U;
                if (ref_vbuck < (int) VBUCK_REF_ADC) {
                    ref_vbuck += (int) VBUCK_RAMP_STEP;
                    if (ref_vbuck > (int) VBUCK_REF_ADC) ref_vbuck = (int) VBUCK_REF_ADC; // clamp
                }
            }

            // Brownout ? drop back to IDLE if VIN falls below OFF threshold
            if (adc_vin < VIN_TH_OFF_ADC) {
                start_tmr_ticks = 0U;
                fsm_state = FSM_IDLE;
            }
            break;

        default:
            fsm_state = FSM_IDLE;
            break;
    }
}

// -----------------------------------------------------------------------------
// ADC Channel callback ? capture VIN/VOUT raw samples
// -----------------------------------------------------------------------------

static void AN1_INT(enum ADC_CHANNEL channel, uint16_t adcVal) {
    (void) channel; // unused in this callback
    (void) adcVal;

    // Optionally show a short LED pulse every N samples without double-toggle
    static uint8_t led_div = 0U;
    if ((++led_div & 0x0F) == 0) { // every 16th sample
        LED_RED_Toggle();
    }

    // Direct reads of ADCBUFx based on MCC buffer assignment
    adc_vin_raw = ADCBUF1; // VIN
    adc_vout_raw = ADCBUF0; // VOUT

    //VCOMP_Update(&VCOMP);
    //VCOMP_PTermUpdate(&VCOMP);
}

// -----------------------------------------------------------------------------
// Scaling and threshold pre-computation
// -----------------------------------------------------------------------------

static void ScaleCalculate(void) {
    if (ADC_MAX_COUNT != 0U) {
        // 64-bit math keeps precision (costly on 16-bit core but done once here)
        VIN_SCALE_X100 = ((int64_t) VREF_MV * (VIN_R1_OHM + VIN_R2_OHM) * 100) / ((int64_t) VIN_R2_OHM * ADC_MAX_COUNT);
        VOUT_SCALE_X100 = ((int64_t) VREF_MV * (VOUT_R1_OHM + VOUT_R2_OHM) * 100) / ((int64_t) VOUT_R2_OHM * ADC_MAX_COUNT);
    } else {
        VIN_SCALE_X100 = 1;
        VOUT_SCALE_X100 = 1;
    }

    VIN_TH_ON_ADC = (uint32_t) ((((int64_t) VIN_TH_ON_MV * 100) + (VIN_SCALE_X100 / 2)) / VIN_SCALE_X100);
    VIN_TH_OFF_ADC = (uint32_t) ((((int64_t) VIN_TH_OFF_MV * 100) + (VIN_SCALE_X100 / 2)) / VIN_SCALE_X100);
    VBUCK_REF_ADC = (uint32_t) ((((int64_t) VBUCK_REF_MV * 100) + (VOUT_SCALE_X100 / 2)) / VOUT_SCALE_X100);

#ifdef DEBUG
    printf("\r\nSCALE CALCULATIONS\r\n");
    printf("VIN_SCALE_X100:  %lld\r\n", VIN_SCALE_X100);
    printf("VOUT_SCALE_X100: %lld\r\n", VOUT_SCALE_X100);
    printf("VIN ON  threshold (ADC):  %lu\r\n", (unsigned long) VIN_TH_ON_ADC);
    printf("VIN OFF threshold (ADC):  %lu\r\n", (unsigned long) VIN_TH_OFF_ADC);
    printf("VBUCK REF         (ADC):  %lu\r\n\r\n", (unsigned long) VBUCK_REF_ADC);
#endif
}

// -----------------------------------------------------------------------------
// Convert last raw samples to millivolts and print (debug)
// -----------------------------------------------------------------------------

static void VoltageReadout(void) {
    // Latch the latest raw ADC readings from the interrupt context (16-bit atomic)
    adc_vin = adc_vin_raw;
    adc_vout = adc_vout_raw;

    // Convert raw ADC -> millivolts
    int64_t vin_temp = ((int64_t) adc_vin * VIN_SCALE_X100) / 100;
    int64_t vout_temp = ((int64_t) adc_vout * VOUT_SCALE_X100) / 100;

    vin_mv = (uint32_t) vin_temp;
    vout_mv = (uint32_t) vout_temp;

#ifdef DEBUG
    printf("\r\nVIN  ADC: %u => %lu mV\r\n", adc_vin, (unsigned long) vin_mv);
    printf("VOUT ADC: %u => %lu mV\r\n\r\n", adc_vout, (unsigned long) vout_mv);
#endif
}

// -----------------------------------------------------------------------------
// Voltage-mode controller wiring (PowerSmart DCLib wrapper)
// -----------------------------------------------------------------------------

static uint16_t VCOMP_ControllerInitialize(void) {
    volatile uint16_t retval = 0U; // function call verification

    // Primary input (feedback)
    VCOMP.Ports.Source.ptrAddress = &adc_vout_raw; // ADC buffer variable (feedback)

    // Primary output (actuation)
    VCOMP.Ports.Target.ptrAddress = &PG1DC; // PWM duty SFR (unit: PG clock ticks)

    // Control reference (soft-start ramped target)
    VCOMP.Ports.ptrControlReference = (unsigned*) &ref_vbuck;

    // Output limits (in PG1DC units)
    VCOMP.Limits.MinOutput = 500; // ~10% of PG1PER (verify w/ your PWM period)
    VCOMP.Limits.MaxOutput = 9000; // ~90% of PG1PER

    // Initialize controller data arrays and scalers
    retval = VCOMP_Initialize(&VCOMP);

    DELAY_milliseconds(1000);
    return retval;
}

// -----------------------------------------------------------------------------
// Input-capture callbacks ? derive duty of TOP FET switching
// -----------------------------------------------------------------------------

// Rising-edge callback (SCCP1)

static void FET_TOP_Rise_Handler(void)
{
    // Read a single timestamp per interrupt; store only
    if (!SCCP1_InputCapture_IsBufferEmpty()) {
        uint32_t tr = SCCP1_InputCapture_DataRead();
        // Shift current -> prev, then latch new rise
        fet_temp_top.rise_prev_ts = fet_temp_top.rise_curr_ts;
        fet_temp_top.rise_curr_ts = tr;
        fet_temp_top.new_rise = 1U;
    }

    if (SCCP1_InputCapture_HasBufferOverflowed()) {
        SCCP1_InputCapture_OverflowFlagClear();
        fet_temp_top.overflow = 1U;   // main can react/log
    }
}

// Falling-edge callback (SCCP2)

static void FET_TOP_Fall_Handler(void)
{
    // Read a single timestamp per interrupt; store only
    if (!SCCP2_InputCapture_IsBufferEmpty()) {
        uint32_t tf = SCCP2_InputCapture_DataRead();
        fet_temp_top.fall_ts = tf;
        fet_temp_top.new_fall = 1U;
    }

    if (SCCP2_InputCapture_HasBufferOverflowed()) {
        SCCP2_InputCapture_OverflowFlagClear();
        fet_temp_top.overflow = 1U;   // main can react/log
    }
}

// -----------------------------------------------------------------------------
// Temperature telemetry task ? prints duty cycle & junction temp over UART
// -----------------------------------------------------------------------------

static void TemperatureTelemetryTask(void)
{
    static uint32_t t_last_ms = 0;

    // ---- Consume edge flags and compute once per call (no work in ISR) ----
    // Snapshot edge flags & timestamps (simple reads are acceptable here)
    uint8_t  have_rise = fet_temp_top.new_rise;
    uint8_t  have_fall = fet_temp_top.new_fall;
    uint32_t rise_prev = fet_temp_top.rise_prev_ts;
    uint32_t rise_curr = fet_temp_top.rise_curr_ts;
    uint32_t fall      = fet_temp_top.fall_ts;

    if (have_rise) fet_temp_top.new_rise = 0U;
    if (have_fall) fet_temp_top.new_fall = 0U;

    // On each new rise, form a period. If a fall occurred within that window,
    // also form a high-time for that cycle.
    if (have_rise) {
        uint32_t period = rise_curr - rise_prev; // wraps OK
        if (period != 0U) {
            uint32_t high = fall - rise_prev;    // wraps OK
            if (have_fall && high <= period) {
                // duty_q15 = (high << 15) / period
                uint64_t num = ((uint64_t)high << 15);
                uint16_t duty_now = (uint16_t)(num / (uint64_t)period);

                // IIR filter with signed diff to avoid wrap
                uint16_t y = fet_temp_top.duty_q15;
                uint16_t x = duty_now;
                int32_t  diff = (int32_t)x - (int32_t)y;
                uint16_t y_new = (uint16_t)((int32_t)y + (diff * (int32_t)TEMP_IIR_ALPHA_NUM) / (int32_t)TEMP_IIR_ALPHA_DEN);

                fet_temp_top.duty_q15 = y_new;
                fet_temp_top.valid    = 1U;
            }
        }
    }

    // ---- Snapshot g_ms without disabling interrupts (double-read) ----
    uint32_t now_ms_1, now_ms_2;
    do { now_ms_1 = g_ms; now_ms_2 = g_ms; } while (now_ms_1 != now_ms_2);
    uint32_t now_ms = now_ms_2;

    // ---- Rate-limit printing ----
    if ((uint32_t)(now_ms - t_last_ms) < TEMP_PWM_PRINT_MS) {
        return;
    }
    t_last_ms = now_ms;

    if (fet_temp_top.valid) {
        uint16_t dq = fet_temp_top.duty_q15;
        if (dq > 32767u) dq = 32767u; // clamp
        uint16_t duty_percent = (uint16_t)(((uint32_t)dq * 100u + 16384u) / 32768u);
        float tempC = temp_q15_to_celsius(dq);
        printf("TEMP duty=%u%%  TJ=%.1f C", duty_percent, (double)tempC);
    } else {
        printf("TEMP: syncing...
");
    }
}
// -----------------------------------------------------------------------------
// Application entry
// -----------------------------------------------------------------------------

int main(void) {
    SYSTEM_Initialize();
#ifdef DEBUG
    printf("System Initialized...\r\n");
#endif

    LD2_SetHigh();
    LD3_SetLow();

    PWM_GeneratorEnable(1);
#ifdef DEBUG
    printf("PWM Generator Enabled...\r\n");
#endif

    TMR1_Start();
#ifdef DEBUG
    printf("Timer 1 Enabled...\r\n");
#endif

    VCOMP_ControllerInitialize();
#ifdef DEBUG
    printf("Voltage Mode Controller Initialized...\r\n");
#endif

    TMR1_TimeoutCallbackRegister(&TMR1_INT);
#ifdef DEBUG
    printf("Timer 1 Interrupt Enabled...\r\n");
#endif

    ADC1_ChannelCallbackRegister(&AN1_INT);
#ifdef DEBUG
    printf("ADC 1 Interrupt Enabled...\r\n");
#endif

    // Flush IC FIFOs before enabling callbacks (prevents burst on start)
while (!SCCP1_InputCapture_IsBufferEmpty()) (void)SCCP1_InputCapture_DataRead();
while (!SCCP2_InputCapture_IsBufferEmpty()) (void)SCCP2_InputCapture_DataRead();

// Input capture callbacks ? TEMP pin measurement
SCCP1_InputCapture_CallbackRegister(FET_TOP_Rise_Handler); // TEMP rising edges
SCCP2_InputCapture_CallbackRegister(FET_TOP_Fall_Handler); // TEMP falling edges; // TEMP falling edges
#ifdef DEBUG
    printf("All Interrupts Enabled...\r\n");
#endif

    ScaleCalculate();

    while (1) {
        VoltageReadout();
        TemperatureTelemetryTask();
        DELAY_milliseconds(500);
    }
}
