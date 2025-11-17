/**
 * SCCP1-InputCapture Generated Driver Source File
 * 
 * @file 	  sccp1.c
 * 
 * @ingroup   mccpdriver
 * 
 * @brief 	  This is the generated driver source file for SCCP1-InputCapture driver
 *
 * @skipline @version   Firmware Driver Version 1.3.0
 *
 * @skipline @version   PLIB Version 1.6.5
 *
 * @skipline  Device : dsPIC33CH512MP506
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

// Section: Included Files

#include <xc.h>
#include <stddef.h> 
#include "../sccp1.h"

// Section: File specific functions

static void (*SCCP1_InputCaptureHandler)(void) = NULL;

// Section: Driver Interface

const struct INPUT_CAPTURE_INTERFACE FET_TEMP_TOP_RISING = {
    .Initialize          = &SCCP1_InputCapture_Initialize,
    .Deinitialize        = &SCCP1_InputCapture_Deinitialize,
    .Start               = &SCCP1_InputCapture_Start,
    .Stop                = &SCCP1_InputCapture_Stop,
    .InputCapture_CallbackRegister = &SCCP1_InputCapture_CallbackRegister,
    .Tasks               = NULL,
    .DataRead            = &SCCP1_InputCapture_DataRead,
    .HasBufferOverflowed = &SCCP1_InputCapture_HasBufferOverflowed,
    .IsBufferEmpty       = &SCCP1_InputCapture_IsBufferEmpty,
    .OverflowFlagClear   = &SCCP1_InputCapture_OverflowFlagClear,
};

// Section: Driver Interface Function Definitions

void SCCP1_InputCapture_Initialize(void)
{
    // MOD Every rising edge; CCSEL enabled; TMR32 16 Bit; TMRPS 1:1; CLKSEL FOSC; TMRSYNC disabled; CCPSLP disabled; CCPSIDL disabled; CCPON disabled; 
    CCP1CON1L = 0x211; //The module is disabled, till other settings are configured.
    //SYNC None; ALTSYNC disabled; ONESHOT disabled; TRIGEN disabled; IOPS Each Time Base Period Match; RTRGEN disabled; OPSRC Timer Interrupt Event; 
    CCP1CON1H = 0x0;
    //ASDG 0x0; SSDG disabled; ASDGM disabled; PWMRSEN disabled; 
    CCP1CON2L = 0x0;
    //ICSEL None; AUXOUT Disabled; ICGSM Level-Sensitive mode; OCAEN disabled; OENSYNC disabled; 
    CCP1CON2H = 0x0;
    //PSSACE Tri-state; POLACE disabled; OSCNT None; OETRIG disabled; 
    CCP1CON3H = 0x0;
    //ICOV disabled; ICDIS disabled; SCEVT disabled; ASEVT disabled; TRCLR disabled; TRSET disabled; ICGARM disabled; 
    CCP1STATL = 0x0;
    //TMRL 0x0000; 
    CCP1TMRL = 0x0;
    //TMRH 0x0000; 
    CCP1TMRH = 0x0;
    //PRL 0; 
    CCP1PRL = 0x0;
    //PRH 0; 
    CCP1PRH = 0x0;
    //CMPA 0; 
    CCP1RA = 0x0;
    //CMPB 0; 
    CCP1RB = 0x0;
    //BUFL 0x0000; 
    CCP1BUFL = 0x0;
    //BUFH 0x0000; 
    CCP1BUFH = 0x0;
    
    SCCP1_InputCapture_CallbackRegister(&SCCP1_InputCapture_Callback);

    IFS0bits.CCP1IF = 0;
    // Enabling SCCP1 interrupt
    IEC0bits.CCP1IE = 1;

    CCP1CON1Lbits.CCPON = 1; //Enable Module

}

void SCCP1_InputCapture_Deinitialize(void)
{
    CCP1CON1Lbits.CCPON = 0;
    
    IFS0bits.CCP1IF = 0;
    IEC0bits.CCP1IE = 0;
    
    CCP1CON1L = 0x0;
    CCP1CON1H = 0x0;
    CCP1CON2L = 0x0;
    CCP1CON2H = 0x100;
    CCP1CON3H = 0x0;
    CCP1STATL = 0x0;
    CCP1TMRL = 0x0;
    CCP1TMRH = 0x0;
    CCP1PRL = 0xFFFF;
    CCP1PRH = 0xFFFF;
    CCP1RA = 0x0;
    CCP1RB = 0x0;
    CCP1BUFL = 0x0;
    CCP1BUFH = 0x0;
}

void SCCP1_InputCapture_Start(void)
{
    IFS0bits.CCP1IF = 0;
    // Enable SCCP1 interrupt
    IEC0bits.CCP1IE = 1;
    
    CCP1CON1Lbits.CCPON = 1;
}

void SCCP1_InputCapture_Stop(void)
{
    CCP1CON1Lbits.CCPON = 0;
    
    IFS0bits.CCP1IF = 0;
    // Disable SCCP1 interrupt
    IEC0bits.CCP1IE = 0;
}

void SCCP1_InputCapture_CallbackRegister(void (*handler)(void))
{
    if(NULL != handler)
    {
        SCCP1_InputCaptureHandler = handler;
    }
}

void __attribute__ ((weak)) SCCP1_InputCapture_Callback (void)
{ 

} 

void __attribute__ ( ( interrupt, no_auto_psv ) ) _CCP1Interrupt (void)
{
    if(NULL != SCCP1_InputCaptureHandler)
    {
        (*SCCP1_InputCaptureHandler)();
    } 
    IFS0bits.CCP1IF = 0;
}

uint32_t SCCP1_InputCapture_DataRead(void)
{
    uint32_t captureVal = 0xFFFFFFFFU;

    captureVal = CCP1BUFL;
    captureVal |= ((uint32_t)CCP1BUFH <<16);

    return(captureVal);
}

bool SCCP1_InputCapture_HasBufferOverflowed(void)
{
    return(CCP1STATLbits.ICOV);
}

bool SCCP1_InputCapture_IsBufferEmpty(void)
{
    return(!CCP1STATLbits.ICBNE);
}

void SCCP1_InputCapture_OverflowFlagClear(void)
{
    CCP1STATLbits.ICOV = 0;
}

/**
 End of File
*/
