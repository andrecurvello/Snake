/*
*********************************************************************************************************
* Module     : types.h
* Author      : Barak Gutman
* Description : Standard usage types over the project.
*********************************************************************************************************
*/

#ifndef SNAKE_INCLUDE_TYPES_H_
#define SNAKE_INCLUDE_TYPES_H_

/* Unsigned types */
typedef unsigned char u8_t;
typedef unsigned short u16_t;
typedef unsigned int u32_t;

/* Signed types */
typedef signed char s8_t;
typedef signed short s16_t;
typedef signed int s32_t;

/* Method signature for callbacks in ISR */
typedef void (*callback_t)(void);

#endif /* SNAKE_INCLUDE_TYPES_H_ */
