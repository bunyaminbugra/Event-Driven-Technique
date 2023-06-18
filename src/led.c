/**
  * @file: main.c
  * @author: Bünyamin Bugra Korkmazer
  * @date: June 18, 2023
  * @version: 1.0
  *
  * @brief: Source file for LED control.
  *
  * @details: This file contains the implementation of the functions for LED control. 
  * The LED can be set, reset, toggled, and blinked with specified on and off times.
  *
  * Revision History: 
  * - 1.0.0 (June 18, 2023): Initial release.
  */

#include "main.h"


/** 
  * @brief Initializes an LED.
  * @param port: Pointer to the GPIO port where the LED is connected.
  * @param pin: Number of the pin where the LED is connected.
  * @return: Pointer to the initialized LED object.
  */
led_InitTypeDef* led_Init(GPIO_T *port, unsigned long pin)
{
	/* Allocate memory for LED object */
	led_InitTypeDef *led = (led_InitTypeDef *)malloc(sizeof(led_InitTypeDef));
	
	/* Set the led's GPIO port and pin */
	led->port = port;
	led->pin = pin;
	
	/* Set GPIO pin as output */
	GPIO_SetMode(port, pin, GPIO_MODE_OUTPUT);
	
	/* Reset LED for initial state */
	led_RESET(led);
	
	return led;
}

/** 
  * @brief Deinitializes an LED.
  * @param led: Pointer to the LED object to be deinitialized.
  * @return None
  */
void led_DeInit(led_InitTypeDef *led)
{
	/* Freeing the memory allocated for the led */
	free(led);
}

/** 
  * @brief Turns ON an LED.
  * @param led: Pointer to the LED to turn ON.
  * @return None
  */
void led_SET(led_InitTypeDef *led)
{
	/* Set led's state to HIGH */
	GPIO_PIN_DATA(getPortNumber(led->port), getPinNumber(led->pin)) = 0;
}

/** 
  * @brief Turns OFF an LED.
  * @param led: Pointer to the LED to turn OFF.
  * @return None
  */
void led_RESET(led_InitTypeDef *led)
{
	/* Set led's state to LOW */
	GPIO_PIN_DATA(getPortNumber(led->port), getPinNumber(led->pin)) = 1;
}

/** 
  * @brief Toggles the state of an LED.
  * @param led: Pointer to the LED to toggle.
  * @return None
  */
void led_TOGGLE(led_InitTypeDef *led)
{
	/* Change led's state */
	GPIO_PIN_DATA(getPortNumber(led->port), getPinNumber(led->pin)) ^= 1;
}

/**
  * @brief  Converts a GPIO port pointer to the corresponding port number.
  * @param  port: Pointer to the GPIO port.
  * @return Port number corresponding to the GPIO port.
  */
int getPortNumber(GPIO_T* port)
{
    if (port == PA) 
		return 0;
    else if (port == PB) 
		return 1;
	else if (port == PC) 
		return 2;
	else if (port == PD) 
		return 3;
	else if (port == PE) 
		return 4;
	else if (port == PF) 
		return 5;
	else if (port == PG) 
		return 6;
	else if (port == PH) 
		return 7;

    else return -1;
}

/**
  * @brief  Converts a pin mask to the corresponding pin number.
  * @param  u32PinMask: Pin mask value.
  * @return Pin number corresponding to the pin mask.
  */
int getPinNumber(unsigned long u32PinMask)
{
    if (u32PinMask == BIT0) 
		return 0;
    else if (u32PinMask == BIT1) 
		return 1;
	else if (u32PinMask == BIT2) 
		return 2;
	else if (u32PinMask == BIT3) 
		return 3;
	else if (u32PinMask == BIT4) 
		return 4;
	else if (u32PinMask == BIT5) 
		return 5;
	else if (u32PinMask == BIT6) 
		return 6;
	else if (u32PinMask == BIT7) 
		return 7;
	else if (u32PinMask == BIT8) 
		return 8;
	else if (u32PinMask == BIT9) 
		return 9;
	else if (u32PinMask == BIT10) 
		return 10;
	else if (u32PinMask == BIT11) 
		return 11;
	else if (u32PinMask == BIT12) 
		return 12;
	else if (u32PinMask == BIT13) 
		return 13;
	else if (u32PinMask == BIT14) 
		return 14;
	else if (u32PinMask == BIT15) 
		return 15;

    else return -1;
}
