/**
 * SCCP4-InputCapture Generated Driver Header File 
 * 
 * @file	  inputcapture_interface.h
 * 
 * @ingroup   inputcapturedriver
 * 
 * @brief 	  This is the generated driver header file for the SCCP4-InputCapture driver
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

#ifndef SCCP4_H
#define SCCP4_H

// Section: Included Files
#include <stdbool.h>
#include <stdint.h>
#include "input_capture_interface.h"

// Section: Data Type Definitions

/**
 * @ingroup  inputcapturedriver
 * @brief    Structure object of type INPUT_CAPTURE_INTERFACE with the custom name
 *           given by the user in the Melody Driver User interface. The default name 
 *           e.g. Input_Capture1 can be changed by the user in the INPUT_CAPTURE user interface. 
 *           This allows defining a structure with application specific name using 
 *           the 'Custom Name' field. Application specific name allows the API Portability.
*/
extern const struct INPUT_CAPTURE_INTERFACE FET_TEMP_BOT_FALLING;

/** 
  @ingroup  mccpdriver
  @brief    This macro is used to read the Input Capture timer frequency (in Hz) for 
            SCCP4 instance.
*/
#define SCCP4_CAPTURE_TIMER_FREQUENCY        180000000UL

/**
 * @ingroup  inputcapturedriver
 * @brief    This macro defines the Custom Name for \ref SCCP4_InputCapture_Initialize API
 */
#define FET_TEMP_BOT_FALLING_Initialize SCCP4_InputCapture_Initialize
/**
 * @ingroup  inputcapturedriver
 * @brief    This macro defines the Custom Name for \ref SCCP4_InputCapture_Deinitialize API
 */
#define FET_TEMP_BOT_FALLING_Deinitialize SCCP4_InputCapture_Deinitialize
/**
 * @ingroup  inputcapturedriver
 * @brief    This macro defines the Custom Name for \ref SCCP4_InputCapture_Start API
 */
#define FET_TEMP_BOT_FALLING_Start SCCP4_InputCapture_Start
/**
 * @ingroup  inputcapturedriver
 * @brief    This macro defines the Custom Name for \ref SCCP4_InputCapture_Stop API
 */
#define FET_TEMP_BOT_FALLING_Stop SCCP4_InputCapture_Stop
/**
 * @ingroup  inputcapturedriver
 * @brief    This macro defines the Custom Name for \ref SCCP4_InputCapture_Tasks API
 */
#define FET_TEMP_BOT_FALLING_Tasks SCCP4_InputCapture_Tasks
/**
 * @ingroup  inputcapturedriver
 * @brief    This macro defines the Custom Name for \ref SCCP4_InputCapture_DataRead API
 */
#define FET_TEMP_BOT_FALLING_DataRead SCCP4_InputCapture_DataRead
/**
 * @ingroup  inputcapturedriver
 * @brief    This macro defines the Custom Name for \ref SCCP4_InputCapture_HasBufferOverflowed API
 */
#define FET_TEMP_BOT_FALLING_HasBufferOverflowed SCCP4_InputCapture_HasBufferOverflowed
/**
 * @ingroup  inputcapturedriver
 * @brief    This macro defines the Custom Name for \ref SCCP4_InputCapture_IsBufferEmpty API
 */
#define FET_TEMP_BOT_FALLING_IsBufferEmpty SCCP4_InputCapture_IsBufferEmpty
/**
 * @ingroup  inputcapturedriver
 * @brief    This macro defines the Custom Name for \ref SCCP4_InputCapture_OverflowFlagClear API
 */
#define FET_TEMP_BOT_FALLING_OverflowFlagClear SCCP4_InputCapture_OverflowFlagClear
/**
 * @ingroup  inputcapturedriver
 * @brief    This macro defines the Custom Name for \ref SCCP4_InputCapture_CallbackRegister API
 */
#define FET_TEMP_BOT_FALLING_InputCapture_CallbackRegister SCCP4_InputCapture_CallbackRegister

// Section: Driver Interface Functions

/**
 * @ingroup  inputcapturedriver
 * @brief    Initializes the SCCP4-InputCapture module
 * @param    none
 * @return   none  
 */
void SCCP4_InputCapture_Initialize (void);

/**
 * @ingroup  inputcapturedriver
 * @brief    Deinitializes the SCCP4-InputCapture to POR values
 * @param    none
 * @return   none  
 */
void SCCP4_InputCapture_Deinitialize(void);

/**
 * @ingroup  inputcapturedriver
 * @brief    Starts the InputCapture operation
 * @pre      SCCP4_InputCapture_Initialize must be called
 * @param    none
 * @return   none  
 */
void SCCP4_InputCapture_Start(void);

/**
 * @ingroup  inputcapturedriver
 * @brief    Stops the InputCapture operation
 * @pre 	 SCCP4_InputCapture_Initialize must be called
 * @param    none
 * @return   none  
 */
void SCCP4_InputCapture_Stop(void);


/**
 * @ingroup   inputcapturedriver
 * @brief      This function can be used to override default callback and to 
 *             define custom callback for SCCP4 InputCapture event.
 * @param[in]  handler - Address of the callback function  
 * @return     none    
 */
void SCCP4_InputCapture_CallbackRegister(void (*handler)(void));

/**
 * @ingroup  inputcapturedriver
 * @brief    This is the default callback with weak attribute. The user can override 
 *           and implement the default callback without weak attribute or can register 
 *           a custom callback function using  SCCP4_InputCaptureCallbackRegister.
 * @param    none
 * @return   none 
 */
void SCCP4_InputCapture_Callback(void);

/**
 * @ingroup  inputcapturedriver
 * @brief 	 Reads the captured value
 * @pre 	 \ref SCCP4_InputCapture_Initialize must be called.
 * @param    none
 * @return   Returns the captured value
 */
uint32_t SCCP4_InputCapture_DataRead(void);


/**
 * @ingroup  inputcapturedriver
 * @brief 	 Returns the buffer overflow status
 * @pre 	 \ref SCCP4_InputCapture_Initialize must be called
 * @param    none
 * @return   true  - input capture buffer has overflowed
 * @return   false - input capture buffer has not overflowed
 */
bool SCCP4_InputCapture_HasBufferOverflowed(void);


/**
 * @ingroup  inputcapturedriver
 * @brief	 Returns the buffer empty status
 * @pre 	 \ref SCCP4_InputCapture_Initialize must be called
 * @param    none
 * @return   true   -  input capture buffer is empty
 * @return   false  -  input capture buffer is not empty
 */
bool SCCP4_InputCapture_IsBufferEmpty(void);

/**
 * @ingroup  inputcapturedriver
 * @brief	 Clears the buffer overflow status flag
 * @pre 	 \ref SCCP4_InputCapture_Initialize must be called
 * @param    none
 * @return   none      
 */
void SCCP4_InputCapture_OverflowFlagClear(void);

#endif //SCCP4_H

/**
 End of File
*/


