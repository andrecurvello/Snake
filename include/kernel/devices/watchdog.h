/*
*********************************************************************************************************
* Module     : watchdog.h
* Author      : Barak Gutman
* Date		 : 12/07/2013
* Description : Header file for watchdog.h
*
* A watchdog timer generate nonmaskable interrupts or a reset when a time-out value is reached.
* The watchdog timer module generates the first time-out signal when the 32-bit
* counter reaches to zero state after being enabled - at this state watchdog's ISR called.
* After the first time-out event the 32 bit counter is re-loaded with the value of the Watchdog Timer Load
* register and the timer resumes counting down from that value.
* Once the watchdog timer has beed configured the watchdog timer lock register is written,
* which prevents the timer configuration from being inadvertently altered by software.
* If the timer counts down to it's zero state again before the FIRST TIMEOUT INTERRUPT IS CLEARD
* and the reset signal has beed enabled the watchdog timer second timeout resets the software (calls c_init00).
*********************************************************************************************************
*/

#ifndef SNAKE_INCLUDE_DEVICES_WATCHDOG_H_
#define SNAKE_INCLUDE_DEVICES_WATCHDOG_H_

#include "include/misc/types.h"
#include <ti/sysbios/hal/Hwi.h>

/*
*****************************************************************************
* If building with a C++ compiler, make all of the definitions in this header
* have a C binding.
*****************************************************************************
*/
#ifdef __cplusplus
extern "C"
{
#endif

/*
*********************************************************************************************************
* Structures
*********************************************************************************************************
*/

/*
*********************************************************************************************************
* SWatchdogParameters
*
* Description: Structure that contains the values to init the watchdog module
*********************************************************************************************************
*/
typedef struct
{
	// Interval value for the watchdog. the interval is in milliseconds.
	size_t		nTimetout;

	// Hook function that called in the ISR
	callback_t 	pTimeoutCallback;

}SWatchdogParameters;

/*
*********************************************************************************************************
* Constants
*********************************************************************************************************
*/
#define		WATCHDOG_INVALID_TOUT									0
#define		WATCHDOG_INTERRUPT_VECTOR_NUMBER				34
#define		WATCHDOG_INTERRUPT_NUMBER							18

/*
*********************************************************************************************************
* Private Globals
*********************************************************************************************************
*/
// The watchdog's os hardware-interrupt handler
static Hwi_Handle g_hWatchdogInterruptHandler;

// The hook function that called in the ISR
static SWatchdogParameters g_sWatchdogParams;

/*
*********************************************************************************************************
* Interrupt Service Routine Prototype
*********************************************************************************************************
*/
void Watchdog_TimeoutReachedISR(void);

/*
*********************************************************************************************************
* Public Function Prototypes
*********************************************************************************************************
*/

/*
*********************************************************************************************************
* Watchdog_Init()
*
* Description: Initialize Watchdog-Timer module. must be called before any other Watchdog functions.
* Arguments  :
* 					sParameters - This structure contains all the relevant parameters to init the Watchdog module.
*
* Returns    : none
*********************************************************************************************************
*/
void Watchdog_Init (SWatchdogParameters* sParameters);

/*
*********************************************************************************************************
* Watchdog_Run()
*
* Description: Enables the watchdog module.
* Arguments  : none
* Returns    : none
*********************************************************************************************************
*/
void Watchdog_Run (void);

/*
*********************************************************************************************************
* Watchdog_Disable()
*
* Description: Disables the watchdog module.
* Arguments  : none
* Returns    : none
*********************************************************************************************************
*/
void Watchdog_Kill (void);

/*
*****************************************************************************
* Mark the end of the C bindings section for C++ compilers.
*****************************************************************************
*/
#ifdef __cplusplus
}
#endif

#endif /* SNAKE_INCLUDE_DEVICES_WATCHDOG_H_ */
