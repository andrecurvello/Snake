/*
*********************************************************************************************************
* Module     : led.c
* Author     : Barak Gutman
* Date		: 29/06/2013
* Description: User-LED Driver Routines
*********************************************************************************************************
*/

/*
*********************************************************************************************************
* Include Header Files
*********************************************************************************************************
*/
#include "include/types.h"
#include "include/kernel/devices/led.h"
#include <inc/hw_types.h>
#include <inc/hw_memmap.h>
#include <driverlib/gpio.h>
#include <driverlib/sysctl.h>

void LED_Init (void)
{
	// The peripheral clock must be enabled by setting the appropriate GPIO Port bit field
	// in the RCGC2 register.
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

	// Configure the GPIO Port F Pin 0 to Input.
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0);
}


void LED_SetDisplay (const ELEDDisplay eDisplayToSet)
{
	if (E_LED_DISPLAY_NUM  >= eDisplayToSet ||
			E_LED_DISPLAY_NUM <= eDisplayToSet)
	{
		// Write to the GPIO-Data Register "1" or "0"
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, (u8_t)eDisplayToSet);
	}
}

void LED_Toggle (void)
{
	// Read the current state of the LED.
	u8_t bCurrentLedStatus = (u8_t)GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);

	// Flip the state of the LED to ON or OFF.
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, ~bCurrentLedStatus);
}
