/*
*********************************************************************************************************
* Module     : led.h
* Author      : Barak Gutman
* Date		 : 29/06/2013
* Description : Header file for led.c (User-LED Driver Routines)
*********************************************************************************************************
*/

#ifndef SNAKE_INCLUDE_DEVICES_LED_H_
#define SNAKE_INCLUDE_DEVICES_LED_H_

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
*****************************************************************************
* Enumerations
*****************************************************************************
*/
typedef enum
{
	E_LED_DISPLAY_TURN_OFF = 0, 	// 0 - Led is off
	E_LED_DISPLAY_TURN_ON, 			// 1 - Led is on

	E_LED_DISPLAY_NUM 					// Must be the last. the num of LED Display states.

}ELEDDisplay;

/*
*********************************************************************************************************
* Public Function Prototypes
*********************************************************************************************************
*/

/*
*********************************************************************************************************
* LED_Init()
*
* Description: Initialize LED module. must be called before any other LED functions.
* Arguments  : none
* Returns    : none
*********************************************************************************************************
*/
void LED_Init (void);

/*
*********************************************************************************************************
* LED_SetDisplay()
*
* Description: Set the desired display of the led according to the ELEDDisplay enum.
* Arguments  :
* 					display_to_set = The desired disiplay state. could be E_E_LED_DISPLAY_TURN_OFF or E_LED_DISPLAY_TURN_ON.
*
* Returns    : none
*********************************************************************************************************
*/
void LED_SetDisplay (const ELEDDisplay eDisplayToSet);

/*
*********************************************************************************************************
* LED_Toggle()
*
* Description: Set the opposite state of the led according to the current state.
* 					if the current state is ON then it switch to OFF etc...
* Arguments  : none
* Returns    : none
*********************************************************************************************************
*/
void LED_Toggle (void);
/*
*****************************************************************************
* Mark the end of the C bindings section for C++ compilers.
*****************************************************************************
*/
#ifdef __cplusplus
}
#endif

#endif /* SNAKE_INCLUDE_DEVICES_LED_H_ */
