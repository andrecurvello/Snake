/*
*********************************************************************************************************
* Module     : uart.h
* Author      : Barak Gutman
* Date		 : 20/07/2013
* Description : Header file for uart.c (Uart Module Driver Routines)
*********************************************************************************************************
*/

#ifndef SNAKE_INCLUDE_KERNEL_DEVICES_UART_H_
#define SNAKE_INCLUDE_KERNEL_DEVICES_UART_H_

#include "include/types.h"
#include <inc/hw_types.h>
#include <inc/hw_memmap.h>
#include <driverlib/uart.h>


/*****************************************************************************
 * If building with a C++ compiler, make all of the definitions in this header
 * have a C binding.
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

/*
*********************************************************************************************************
* Constants
*********************************************************************************************************
*/
#define		UART_BUFFER_SIZE		500

/*
*****************************************************************************
* Enumerations
*****************************************************************************
*/
typedef enum
{
	E_UART_COM_PORT_1 ,
	E_UART_COM_PORT_2 ,
	E_UART_COM_PORT_3 ,

	// Don't delete. must be last. indicates how much com-ports we have.
	E_UART_COM_PORT_NUM

}EUARTComPort;

typedef enum
{
	E_UART_BAUDRATE_2400 = 2400,
	E_UART_BAUDRATE_4800 = 4800,
	E_UART_BAUDRATE_9600 = 9600,
	E_UART_BAUDRATE_14400 = 14400,
	E_UART_BAUDRATE_19200 = 19200,
	E_UART_BAUDRATE_38400 = 38400,
	E_UART_BAUDRATE_57600 = 57600,
	E_UART_BAUDRATE_115200 = 115200

}EUARTBaudrate;

typedef enum
{
	E_UART_WORD_5_BITS = UART_CONFIG_WLEN_5,
	E_UART_WORD_6_BITS = UART_CONFIG_WLEN_6,
	E_UART_WORD_7_BITS = UART_CONFIG_WLEN_7,
	E_UART_WORD_8_BITS = UART_CONFIG_WLEN_8

}EUARTWordLength;

typedef enum
{
	E_UART_BIT_PARITY_NONE = UART_CONFIG_PAR_NONE,
	E_UART_BIT_PARITY_EVEN = UART_CONFIG_PAR_EVEN,
	E_UART_BIT_PARITY_ODD = UART_CONFIG_PAR_ODD,
	E_UART_BIT_PARITY_ONE = UART_CONFIG_PAR_ONE,
	E_UART_BIT_PARITY_ZERO = UART_CONFIG_PAR_ZERO

}EUARTParity;

typedef enum
{
	E_UART_BIT_STOP_ONE = UART_CONFIG_STOP_ONE,
	E_UART_BIT_STOP_TWO = UART_CONFIG_STOP_TWO

}EUARTStopBit;

/*
*********************************************************************************************************
* Structures
*********************************************************************************************************
*/

/*
*********************************************************************************************************
* SUARTParameters
*
* Description: Structure that contains the values to init specific uart module
*********************************************************************************************************
*/
typedef struct
{
	// Which port I desired to init and use
	EUARTComPort eComPort;

	// The desired baudrate of the port
	EUARTBaudrate eBaurdrate;

	// The length of that data in bits that the uart can tx and rx
	EUARTWordLength eDataLength;

	// Type of parity bit
	EUARTParity eParity;

	// How much stop-bits to set
	EUARTStopBit eStopBit;

}SUARTParameters;

/*
*********************************************************************************************************
* SUARTHandle
*
* Description: Handle to the specific initialize uart module
*********************************************************************************************************
*/
typedef struct
{
	void* pUARTPort;

}SUARTHandle;

typedef struct
{
	// UART's base register
	u32_t dwBaseUARTRegister;

	// The value that need to write into the RCGC1 register to enable the clocking to the specific uart module
	u32_t dwSysCtrlPeripheralUARTValue;

	// All the UARTs on the device are connected to gpios ports. so we need to enable the clocking
	// to specific gpio module too according to the datasheet.
	// This member contains the value to write to the RCGC2 register to enable the clocking to the specific gpio module.
	u32_t dwSysCtrlPeripheralUARTGpioPinsValue;

}SUARTPort;
#if 0
typedef struct
{

}SUARTBuffer;
#endif
/*
*********************************************************************************************************
* Private Globals
*********************************************************************************************************
*/
static SUARTPort g_sUARTPorts[E_UART_COM_PORT_NUM] =
{
		// UART 0 module
		{UART0_BASE, 		SYSCTL_PERIPH_UART0, 		SYSCTL_PERIPH_GPIOA},

		// UART 1 module
		{UART1_BASE, 		SYSCTL_PERIPH_UART1, 		SYSCTL_PERIPH_GPIOD},

		// UART 2 module
		{UART2_BASE,  		SYSCTL_PERIPH_UART2, 		SYSCTL_PERIPH_GPIOG}
};

/*
*********************************************************************************************************
* Public Function Prototypes
*********************************************************************************************************
*/

void UART_Init(SUARTParameters* sUartParameters, SUARTHandle* o_sUartHandle);

/*****************************************************************************
  * Mark the end of the C bindings section for C++ compilers.
  *****************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* SNAKE_INCLUDE_KERNEL_DEVICES_UART_H_ */
