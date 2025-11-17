/**
 * PINS Generated Driver Header File 
 * 
 * @file      pins.h
 *            
 * @defgroup  pinsdriver Pins Driver
 *            
 * @brief     The Pin Driver directs the operation and function of 
 *            the selected device pins using dsPIC MCUs.
 *
 * @skipline @version   Firmware Driver Version 1.0.2
 *
 * @skipline @version   PLIB Version 1.3.0
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

#ifndef PINS_H
#define PINS_H
// Section: Includes
#include <xc.h>

// Section: Device Pin Macros

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB10 GPIO Pin which has a custom name of TOP_FAULT to High
 * @pre      The RB10 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define TOP_FAULT_SetHigh()          (_LATB10 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB10 GPIO Pin which has a custom name of TOP_FAULT to Low
 * @pre      The RB10 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define TOP_FAULT_SetLow()           (_LATB10 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB10 GPIO Pin which has a custom name of TOP_FAULT
 * @pre      The RB10 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define TOP_FAULT_Toggle()           (_LATB10 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB10 GPIO Pin which has a custom name of TOP_FAULT
 * @param    none
 * @return   none  
 */
#define TOP_FAULT_GetValue()         _RB10

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB10 GPIO Pin which has a custom name of TOP_FAULT as Input
 * @param    none
 * @return   none  
 */
#define TOP_FAULT_SetDigitalInput()  (_TRISB10 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB10 GPIO Pin which has a custom name of TOP_FAULT as Output
 * @param    none
 * @return   none  
 */
#define TOP_FAULT_SetDigitalOutput() (_TRISB10 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB12 GPIO Pin which has a custom name of BOTTOM_OC to High
 * @pre      The RB12 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define BOTTOM_OC_SetHigh()          (_LATB12 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB12 GPIO Pin which has a custom name of BOTTOM_OC to Low
 * @pre      The RB12 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define BOTTOM_OC_SetLow()           (_LATB12 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB12 GPIO Pin which has a custom name of BOTTOM_OC
 * @pre      The RB12 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define BOTTOM_OC_Toggle()           (_LATB12 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB12 GPIO Pin which has a custom name of BOTTOM_OC
 * @param    none
 * @return   none  
 */
#define BOTTOM_OC_GetValue()         _RB12

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB12 GPIO Pin which has a custom name of BOTTOM_OC as Input
 * @param    none
 * @return   none  
 */
#define BOTTOM_OC_SetDigitalInput()  (_TRISB12 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB12 GPIO Pin which has a custom name of BOTTOM_OC as Output
 * @param    none
 * @return   none  
 */
#define BOTTOM_OC_SetDigitalOutput() (_TRISB12 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB13 GPIO Pin which has a custom name of BOTTOM_FAULT to High
 * @pre      The RB13 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define BOTTOM_FAULT_SetHigh()          (_LATB13 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB13 GPIO Pin which has a custom name of BOTTOM_FAULT to Low
 * @pre      The RB13 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define BOTTOM_FAULT_SetLow()           (_LATB13 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB13 GPIO Pin which has a custom name of BOTTOM_FAULT
 * @pre      The RB13 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define BOTTOM_FAULT_Toggle()           (_LATB13 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB13 GPIO Pin which has a custom name of BOTTOM_FAULT
 * @param    none
 * @return   none  
 */
#define BOTTOM_FAULT_GetValue()         _RB13

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB13 GPIO Pin which has a custom name of BOTTOM_FAULT as Input
 * @param    none
 * @return   none  
 */
#define BOTTOM_FAULT_SetDigitalInput()  (_TRISB13 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB13 GPIO Pin which has a custom name of BOTTOM_FAULT as Output
 * @param    none
 * @return   none  
 */
#define BOTTOM_FAULT_SetDigitalOutput() (_TRISB13 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD0 GPIO Pin which has a custom name of TOP_OC to High
 * @pre      The RD0 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define TOP_OC_SetHigh()          (_LATD0 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD0 GPIO Pin which has a custom name of TOP_OC to Low
 * @pre      The RD0 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define TOP_OC_SetLow()           (_LATD0 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RD0 GPIO Pin which has a custom name of TOP_OC
 * @pre      The RD0 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define TOP_OC_Toggle()           (_LATD0 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RD0 GPIO Pin which has a custom name of TOP_OC
 * @param    none
 * @return   none  
 */
#define TOP_OC_GetValue()         _RD0

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD0 GPIO Pin which has a custom name of TOP_OC as Input
 * @param    none
 * @return   none  
 */
#define TOP_OC_SetDigitalInput()  (_TRISD0 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD0 GPIO Pin which has a custom name of TOP_OC as Output
 * @param    none
 * @return   none  
 */
#define TOP_OC_SetDigitalOutput() (_TRISD0 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD8 GPIO Pin which has a custom name of LD2 to High
 * @pre      The RD8 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define LD2_SetHigh()          (_LATD8 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD8 GPIO Pin which has a custom name of LD2 to Low
 * @pre      The RD8 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define LD2_SetLow()           (_LATD8 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RD8 GPIO Pin which has a custom name of LD2
 * @pre      The RD8 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define LD2_Toggle()           (_LATD8 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RD8 GPIO Pin which has a custom name of LD2
 * @param    none
 * @return   none  
 */
#define LD2_GetValue()         _RD8

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD8 GPIO Pin which has a custom name of LD2 as Input
 * @param    none
 * @return   none  
 */
#define LD2_SetDigitalInput()  (_TRISD8 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD8 GPIO Pin which has a custom name of LD2 as Output
 * @param    none
 * @return   none  
 */
#define LD2_SetDigitalOutput() (_TRISD8 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD13 GPIO Pin which has a custom name of LD3 to High
 * @pre      The RD13 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define LD3_SetHigh()          (_LATD13 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD13 GPIO Pin which has a custom name of LD3 to Low
 * @pre      The RD13 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define LD3_SetLow()           (_LATD13 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RD13 GPIO Pin which has a custom name of LD3
 * @pre      The RD13 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define LD3_Toggle()           (_LATD13 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RD13 GPIO Pin which has a custom name of LD3
 * @param    none
 * @return   none  
 */
#define LD3_GetValue()         _RD13

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD13 GPIO Pin which has a custom name of LD3 as Input
 * @param    none
 * @return   none  
 */
#define LD3_SetDigitalInput()  (_TRISD13 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD13 GPIO Pin which has a custom name of LD3 as Output
 * @param    none
 * @return   none  
 */
#define LD3_SetDigitalOutput() (_TRISD13 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD15 GPIO Pin which has a custom name of LED_RED to High
 * @pre      The RD15 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define LED_RED_SetHigh()          (_LATD15 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD15 GPIO Pin which has a custom name of LED_RED to Low
 * @pre      The RD15 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define LED_RED_SetLow()           (_LATD15 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RD15 GPIO Pin which has a custom name of LED_RED
 * @pre      The RD15 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define LED_RED_Toggle()           (_LATD15 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RD15 GPIO Pin which has a custom name of LED_RED
 * @param    none
 * @return   none  
 */
#define LED_RED_GetValue()         _RD15

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD15 GPIO Pin which has a custom name of LED_RED as Input
 * @param    none
 * @return   none  
 */
#define LED_RED_SetDigitalInput()  (_TRISD15 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD15 GPIO Pin which has a custom name of LED_RED as Output
 * @param    none
 * @return   none  
 */
#define LED_RED_SetDigitalOutput() (_TRISD15 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Initializes the PINS module
 * @param    none
 * @return   none  
 */
void PINS_Initialize(void);



#endif
