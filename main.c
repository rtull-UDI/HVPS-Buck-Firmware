
#include <stdint.h>                             
#include <stdbool.h>                          
#include <stddef.h>                              
#include <xc.h>
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

// ADC Config
#define ADC_MAX_COUNT 4095
#define VREF                      3300  // Representing voltage in millivolts for integer math

// Voltage divider resistors
#define VIN_R1 99000  // Upper resistor in ohms
#define VIN_R2 1000   // Lower resistor in ohms
#define VOUT_R1 196200
#define VOUT_R2 3195

// Soft Start Ramp "speed"
#define VBUCK_RAMP ((uint32_t)1)

// mV value variables for important setpoints (ALL IN MILLIVOLTS)
uint32_t VIN_TH_ON = 210000;
uint32_t VIN_TH_OFF = 205000;
uint32_t VBUCK_REF = 180000;

//ADC scale factors scaled for integer math
int64_t VIN_SCALE_INT = 0;
int64_t VOUT_SCALE_INT = 0;

// ADC value variables for important setpoints
uint32_t VIN_TH_ON_ADC = 0;
uint32_t VIN_TH_OFF_ADC = 0;
uint32_t VBUCK_REF_ADC = 0;

// unsigned int 16 variables for raw ADC values
volatile uint16_t adc_vin_raw = 0;
volatile uint16_t adc_vout_raw = 0;

volatile uint16_t adc_vin = 0;
volatile uint16_t adc_vout = 0;

volatile uint32_t vin_real = 0;
volatile uint32_t vout_real = 0;

// Reference as controlled by soft start routine
volatile int ref_vbuck = 0;

// State machine Variables

typedef enum {
    FSM_IDLE = 0,
    FSM_SOFT_START = 1
} fsm_state_t;

volatile fsm_state_t fsm_state = FSM_IDLE;
volatile uint16_t led_tmr = 0;
volatile uint16_t start_tmr = 0;
volatile uint16_t soft_start_counter = 0;

// FET temp monitoring structures

typedef struct {
    volatile uint32_t t_rise_prev;
    volatile uint32_t high_ticks;
    volatile uint32_t period_ticks;
    volatile float duty;
    volatile uint8_t have_rise;
} temp_ic_t;

static temp_ic_t top_temp = {0};

/*
    Main application
 */


void TMR1_INT() {

    if (++led_tmr >= 500) {
        led_tmr = 0;
        LD2_Toggle();
        LD3_Toggle();
    }


    switch (fsm_state) {
        case FSM_IDLE:
            ref_vbuck = 0;
            // Compare raw ADC counts to threshold if desired
            if (adc_vin <= VIN_TH_ON_ADC) {
                start_tmr = 0;
            } else {
                // Prevent overflow by checking against the threshold
                if (start_tmr < 2000) {
                    start_tmr++;
                }
                if (start_tmr >= 2000) {
                    fsm_state = FSM_SOFT_START;
                }
            }
            break;

        case FSM_SOFT_START:
            if (ref_vbuck < VBUCK_REF_ADC) {
                // Increment with saturation
                if (soft_start_counter < 16) {
                    soft_start_counter++;
                }
                if (soft_start_counter >= 16) {
                    soft_start_counter = 0;
                    ref_vbuck += VBUCK_RAMP;
                }
            } else {
                ref_vbuck = VBUCK_REF_ADC; // clamp to final value
            }
            if (adc_vin < VIN_TH_OFF_ADC) {
                start_tmr = 0;
                fsm_state = FSM_IDLE;
            }
            break;
    }
}

void AN1_INT(enum ADC_CHANNEL channel, uint16_t adcVal) {

    LED_RED_Toggle();

    // Ignore the callback parameters
    (void) channel;
    (void) adcVal;

    adc_vin_raw = ADCBUF1; // !!!!!
    adc_vout_raw = ADCBUF0; // !!!!!

    //VCOMP_Update(&VCOMP);
    //VCOMP_PTermUpdate(&VCOMP);

    LED_RED_Toggle();
}

void ScaleCalculate(void) {
    if (ADC_MAX_COUNT != 0) {
        VIN_SCALE_INT = ((int64_t) VREF * (VIN_R1 + VIN_R2) * 100)
                / ((int64_t) VIN_R2 * ADC_MAX_COUNT);

        VOUT_SCALE_INT = ((int64_t) VREF * (VOUT_R1 + VOUT_R2) * 100)
                / ((int64_t) VOUT_R2 * ADC_MAX_COUNT);
    } else {
        VIN_SCALE_INT = 1;
        VOUT_SCALE_INT = 1;
    }

    VIN_TH_ON_ADC = (int32_t) (
            (
            ((int64_t) VIN_TH_ON * 100)
            + (VIN_SCALE_INT / 2)
            )
            / VIN_SCALE_INT
            );

    VIN_TH_OFF_ADC = (int32_t) (
            (
            ((int64_t) VIN_TH_OFF * 100)
            + (VIN_SCALE_INT / 2)
            )
            / VIN_SCALE_INT
            );

    VBUCK_REF_ADC = (int32_t) (
            (
            ((int64_t) VBUCK_REF * 100)
            + (VOUT_SCALE_INT / 2)
            )
            / VOUT_SCALE_INT
            );

    printf("\r\n");
    printf("SCALE CALCULATIONS\r\n");

    printf("VIN_SCALE_INT: %lld\r\n", VIN_SCALE_INT);

    printf("VOUT_SCALE_INT: %lld\r\n", VOUT_SCALE_INT);

    printf("Computed ADC VIN ON Threshold: %ld\r\nComputed ADC VIN OFF Threshold: %ld\r\nComputed ADC VBUCK Reference: %ld\r\n",
            VIN_TH_ON_ADC, VIN_TH_OFF_ADC, VBUCK_REF_ADC);

    printf("\r\n");
}

void VoltageReadout(void) {
    // Copy the latest raw ADC reading from the interrupt
    adc_vin = adc_vin_raw;
    adc_vout = adc_vout_raw;

    // Convert raw ADC -> millivolts
    int64_t temp_vin = ((int64_t) adc_vin * VIN_SCALE_INT) / 100;
    int64_t temp_vout = ((int64_t) adc_vout * VOUT_SCALE_INT) / 100;

    vin_real = (int32_t) temp_vin;
    vout_real = (int32_t) temp_vout;

    printf("\r\n");
    printf("VIN ADC: %u => %lu mV\r\n", adc_vin, vin_real);
    printf("VOUT ADC: %u => %lu mV\r\n", adc_vout, vout_real);
    printf("\r\n");
}

volatile uint16_t VCOMP_ControllerInitialize(void) {
    volatile uint16_t retval = 0; // Auxiliary variable for function call verification (initially set to ZERO = false)

    /* Controller Input and Output Ports Configuration */

    // Configure Controller Primary Input Port
    VCOMP.Ports.Source.ptrAddress = &adc_vout_raw; // Pointer to primary feedback source (e.g. ADC buffer register or variable)

    // Configure Controller Primary Output Port
    VCOMP.Ports.Target.ptrAddress = &PG1DC; // Pointer to primary output target (e.g. SFR register or variable)


    // Configure Control Reference Port
    VCOMP.Ports.ptrControlReference = (unsigned*) &ref_vbuck; // Pointer to control reference (user-variable)

    /* Controller Output Limits Configuration */

    // Primary Control Output Limit Configuration
    VCOMP.Limits.MinOutput = 500; // Minimum control output value = 10%
    VCOMP.Limits.MaxOutput = 9000; // Maximum control output value = 90%

    // Call Assembler Control Library Initialization Function
    retval = VCOMP_Initialize(&VCOMP); // Initialize controller data arrays and number scalers
    DELAY_milliseconds(1000);
    return (retval);

}

void FET_TOP_Rise_Handler(void) {
    // Drain FIFO in case multiple edges queued
    while (!SCCP1_InputCapture_IsBufferEmpty()) {
        uint32_t t = SCCP1_InputCapture_DataRead();
        if (top_temp.have_rise) {
            // full period = (this rise) - (previous rise)
            top_temp.period_ticks = t - top_temp.t_rise_prev; // wraps OK (unsigned math)
            if (top_temp.period_ticks) {
                // duty for the *last* cycle uses the high-time we captured at the fall
                top_temp.duty = (float) top_temp.high_ticks / (float) top_temp.period_ticks;
            }
        }
        top_temp.t_rise_prev = t;
        top_temp.have_rise = 1;
    }

    if (SCCP1_InputCapture_HasBufferOverflowed()) {
        SCCP1_InputCapture_OverflowFlagClear(); // recover if ISR was late
        top_temp.have_rise = 0; // resync
    }
}

void FET_TOP_Fall_Handler(void) {
    while (!SCCP2_InputCapture_IsBufferEmpty()) {
        uint32_t t = SCCP2_InputCapture_DataRead();
        // high-time = (this fall) - (most recent rise)
        top_temp.high_ticks = t - top_temp.t_rise_prev;
    }
    if (SCCP2_InputCapture_HasBufferOverflowed()) {
        SCCP2_InputCapture_OverflowFlagClear();
        // high_ticks may be stale; next rise will resync
    }
}

int main(void) {

    SYSTEM_Initialize();
    printf("System Initialized...\r\n");

    LD2_SetHigh();
    LD3_SetLow();

    PWM_GeneratorEnable(1);
    printf("PWM Generator Enabled...\r\n");

    TMR1_Start();
    printf("Timer 1 Enabled...\r\n");

    VCOMP_ControllerInitialize();
    printf("Voltage Mode Controller Initialized...\r\n");

    TMR1_TimeoutCallbackRegister(&TMR1_INT);
    printf("\r\nTimer 1 Interrupt Enabled...\r\n");
    ADC1_ChannelCallbackRegister(&AN1_INT);
    printf("ADC 1 Interrupt Enabled...\r\n");

    extern void FET_TOP_Rise_Handler(void);
    extern void FET_TOP_Fall_Handler(void);

    SCCP1_InputCapture_CallbackRegister(FET_TOP_Rise_Handler); // rising-only IC
    SCCP2_InputCapture_CallbackRegister(FET_TOP_Fall_Handler); // falling-only IC

    printf("\r\nAll Interrupts Enabled...\r\n");

    ScaleCalculate();

    while (1) {


        VoltageReadout();
        DELAY_milliseconds(500);

    }
}