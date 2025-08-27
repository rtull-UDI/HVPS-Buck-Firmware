/**
 * SCCP3-InputCapture Generated Driver Source File
 * 
 * @file 	  sccp3.c
 * 
 * @ingroup   mccpdriver
 * 
 * @brief 	  This is the generated driver source file for SCCP3-InputCapture driver
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
#include "../sccp3.h"

// Section: File specific functions

static void (*SCCP3_InputCaptureHandler)(void) = NULL;

// Section: Driver Interface

const struct INPUT_CAPTURE_INTERFACE FET_TEMP_BOT_RISING = {
    .Initialize          = &SCCP3_InputCapture_Initialize,
    .Deinitialize        = &SCCP3_InputCapture_Deinitialize,
    .Start               = &SCCP3_InputCapture_Start,
    .Stop                = &SCCP3_InputCapture_Stop,
    .InputCapture_CallbackRegister = &SCCP3_InputCapture_CallbackRegister,
    .Tasks               = &SCCP3_InputCapture_Tasks,
    .DataRead            = &SCCP3_InputCapture_DataRead,
    .HasBufferOverflowed = &SCCP3_InputCapture_HasBufferOverflowed,
    .IsBufferEmpty       = &SCCP3_InputCapture_IsBufferEmpty,
    .OverflowFlagClear   = &SCCP3_InputCapture_OverflowFlagClear,
};

// Section: Driver Interface Function Definitions

void SCCP3_InputCapture_Initialize(void)
{
    // MOD None; CCSEL enabled; TMR32 16 Bit; TMRPS 1:1; CLKSEL FOSC/2; TMRSYNC disabled; CCPSLP disabled; CCPSIDL disabled; CCPON disabled; 
    CCP3CON1L = 0x10; //The module is disabled, till other settings are configured.
    //SYNC None; ALTSYNC disabled; ONESHOT disabled; TRIGEN disabled; IOPS Each Time Base Period Match; RTRGEN disabled; OPSRC Timer Interrupt Event; 
    CCP3CON1H = 0x0;
    //ASDG 0x0; SSDG disabled; ASDGM disabled; PWMRSEN disabled; 
    CCP3CON2L = 0x0;
    //ICSEL None; AUXOUT Disabled; ICGSM Level-Sensitive mode; OCAEN disabled; OENSYNC disabled; 
    CCP3CON2H = 0x0;
    //PSSACE Tri-state; POLACE disabled; OSCNT None; OETRIG disabled; 
    CCP3CON3H = 0x0;
    //ICOV disabled; ICDIS disabled; SCEVT disabled; ASEVT disabled; TRCLR disabled; TRSET disabled; ICGARM disabled; 
    CCP3STATL = 0x0;
    //TMRL 0x0000; 
    CCP3TMRL = 0x0;
    //TMRH 0x0000; 
    CCP3TMRH = 0x0;
    //PRL 0; 
    CCP3PRL = 0x0;
    //PRH 0; 
    CCP3PRH = 0x0;
    //CMPA 0; 
    CCP3RA = 0x0;
    //CMPB 0; 
    CCP3RB = 0x0;
    //BUFL 0x0000; 
    CCP3BUFL = 0x0;
    //BUFH 0x0000; 
    CCP3BUFH = 0x0;
    
    SCCP3_InputCapture_CallbackRegister(&SCCP3_InputCapture_Callback);


    CCP3CON1Lbits.CCPON = 1; //Enable Module

}

void SCCP3_InputCapture_Deinitialize(void)
{
    CCP3CON1Lbits.CCPON = 0;
    
    
    CCP3CON1L = 0x0;
    CCP3CON1H = 0x0;
    CCP3CON2L = 0x0;
    CCP3CON2H = 0x100;
    CCP3CON3H = 0x0;
    CCP3STATL = 0x0;
    CCP3TMRL = 0x0;
    CCP3TMRH = 0x0;
    CCP3PRL = 0xFFFF;
    CCP3PRH = 0xFFFF;
    CCP3RA = 0x0;
    CCP3RB = 0x0;
    CCP3BUFL = 0x0;
    CCP3BUFH = 0x0;
}

void SCCP3_InputCapture_Start(void)
{
    
    CCP3CON1Lbits.CCPON = 1;
}

void SCCP3_InputCapture_Stop(void)
{
    CCP3CON1Lbits.CCPON = 0;
    
}

void SCCP3_InputCapture_CallbackRegister(void (*handler)(void))
{
    if(NULL != handler)
    {
        SCCP3_InputCaptureHandler = handler;
    }
}

void __attribute__ ((weak)) SCCP3_InputCapture_Callback (void)
{ 

} 

void SCCP3_InputCapture_Tasks(void)
{
    if(IFS2bits.CCP3IF == 1)
    {
        if(NULL != SCCP3_InputCaptureHandler)
        {
            (*SCCP3_InputCaptureHandler)();
        }
        IFS2bits.CCP3IF = 0;
    }
}

uint32_t SCCP3_InputCapture_DataRead(void)
{
    uint32_t captureVal = 0xFFFFFFFFU;

    captureVal = CCP3BUFL;
    captureVal |= ((uint32_t)CCP3BUFH <<16);

    return(captureVal);
}

bool SCCP3_InputCapture_HasBufferOverflowed(void)
{
    return(CCP3STATLbits.ICOV);
}

bool SCCP3_InputCapture_IsBufferEmpty(void)
{
    return(!CCP3STATLbits.ICBNE);
}

void SCCP3_InputCapture_OverflowFlagClear(void)
{
    CCP3STATLbits.ICOV = 0;
}

/**
 End of File
*/
