/***********************************
 * File:		Main.cpp
 * Author:	Barak Gutman
 * Date:		29/06/2013
 * Description:
 * 				The entry point of the application.
 *
 ***********************************/
#include "include/types.h"
#include "include/kernel/devices/led.h"
#include "include/kernel/devices/watchdog.h"

#include "ti/sysbios/knl/Clock.h"
#include "ti/sysbios/BIOS.h"
#include "ti/sysbios/knl/Task.h"
#include "ti/sysbios/hal/Hwi.h"

#include <stdio.h>

void myIsr()
{
	//printf("myIsr\n");
	LED_Toggle();
}

void myFxn()
{
	printf("myFxn\n");
	while(1)
	{
	}
}

int main()
{
	printf("Main\n");
	SWatchdogParameters wd_params;
	wd_params.tTimetout = 1000;
	wd_params.pTimeoutCallback = myIsr;

	LED_Init();
	Watchdog_Init(&wd_params);

	Task_Params taskParams;

	// Create task with priority 15
	Task_Params_init(&taskParams);
	taskParams.priority = 15;
	Task_create((Task_FuncPtr)myFxn, &taskParams, NULL);

	Watchdog_Run();

	BIOS_start();
}

