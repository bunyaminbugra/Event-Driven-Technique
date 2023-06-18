/**
  * @file: LED.h
  * @author: Bünyamin Bugra Korkmazer
  * @date: June 18, 2023
  * @version: 1.0
  *
  * @brief: Header file for LED control functions.
  *
  * @details: This file declares the types and functions used in controlling the LED. 
  * It includes the structures for LED and Blink type, as well as the function prototypes.
  *
  * Revision History: 
  * - 1.0.0 (June 18, 2023): Initial release.
  */


#ifndef LED_H
#define LED_H

#include "main.h"

/* Structure for LED Initialization */
typedef struct
{
	GPIO_T *port;		/* GPIO port for the button */
	unsigned long pin;		/* Pin number for the button */
} led_InitTypeDef;

/**
  * @section   Function Prototypes
  * @brief     This section includes function prototypes.
  */

/* Function prototypes for LED control */
led_InitTypeDef* led_Init(GPIO_T *port, unsigned long pin);
void led_DeInit(led_InitTypeDef *led);
void led_SET(led_InitTypeDef *led);
void led_RESET(led_InitTypeDef *led);
void led_TOGGLE(led_InitTypeDef *led);

/*  Helper functions to get port number and pin number from their respective mask values */
int getPortNumber(GPIO_T* port);
int getPinNumber(unsigned long u32PinMask);

#endif
