/*
*********************************************************************************************************
* Module     : led.c
* Author     : Barak Gutman
* Date		: 12/07/2013
* Description: Watchdog-Timer Driver Routines
*********************************************************************************************************
*/
#include "include/kernel/devices/watchdog.h"
#include <inc/hw_ints.h>
#include <inc/hw_types.h>
#include <inc/hw_memmap.h>
#include <driverlib/sysctl.h>
#include <driverlib/watchdog.h>

void Watchdog_TimeoutReachedISR (void)
{
	// Clear the watchdog interrupt
    WatchdogIntClear(WATCHDOG0_BASE);

    // Call to the callback funtcion if there's any callback function...
    if (NULL != g_sWatchdogParams.pTimeoutCallback)
    {
    	g_sWatchdogParams.pTimeoutCallback();
    }
}

void Watchdog_Init (SWatchdogParameters* sParameters)
{
	// OS interrupt params.
	Hwi_Params sWatchdogInterruptParams;

	// Init the structure with default params
	Hwi_Params_init(&sWatchdogInterruptParams);

	// Insure that timout param is valid
	if (WATCHDOG_INVALID_TOUT != sParameters->tTimetout)
	{
		// Save the interval for future usage
		g_sWatchdogParams.tTimetout = sParameters->tTimetout;

		// Sets the hook
		g_sWatchdogParams.pTimeoutCallback = sParameters->pTimeoutCallback;

		// Enable the peripheral clock for the watchdog
		SysCtlPeripheralEnable (SYSCTL_PERIPH_WDOG0);

		// Sets the Watchdog load value (CpuClockMHz * timeout)
		WatchdogReloadSet (WATCHDOG0_BASE, (u32_t)((SysCtlClockGet() / 10) * (float)(g_sWatchdogParams.tTimetout / 100)));

		// Enables at second interrupt reset
		WatchdogResetEnable(WATCHDOG0_BASE);

		// Sets interrupt id
		sWatchdogInterruptParams.eventId = WATCHDOG_INTERRUPT_NUMBER;

		// Sets ISR
		g_hWatchdogInterruptHandler = Hwi_create(WATCHDOG_INTERRUPT_VECTOR_NUMBER,
												 	 (Hwi_FuncPtr)Watchdog_TimeoutReachedISR,
												 	 &sWatchdogInterruptParams,
												 	 NULL);
	}
}

void Watchdog_Run (void)
{
	// Enable the watchdog
	WatchdogEnable(WATCHDOG0_BASE);
}

void Watchdog_Kill (void)
{
	// Stop the clocking to the watchdog module
	SysCtlPeripheralDisable (SYSCTL_PERIPH_WDOG0);

	// Disable the interrupt of the watchdog
	Hwi_disableInterrupt(WATCHDOG_INTERRUPT_VECTOR_NUMBER);

	// Delete the hardware interrupt handler
	Hwi_delete(&g_hWatchdogInterruptHandler);

	// Reset the hook function
	g_sWatchdogParams.pTimeoutCallback = NULL;
}
