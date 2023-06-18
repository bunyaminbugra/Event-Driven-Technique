/** 
  * @file: main.c
  * @author: Bünyamin Buðra Korkmazer
  * @date: June 18, 2023
  * @version: 1.0.0
  *
  * @details: 
  * This file contains the implementation of functions used to configure, read, 
  * and manage the status of a button. It includes functions for initializing a 
  * button, de-initializing a button, reading the button status considering 
  * debounce and long press situations, and a function for reading the button's 
  * current state.
  *
  * Revision History: 
  * - 1.0.0 (June 18, 2023): Initial release.
  */

#include "main.h"

/**
 * @brief Initializes a button
 * @details This function is used to initialize a button with the provided port and pin.
 * It allocates memory for a button object and configures the GPIO pin to be used as input.
 * @param port Pointer to the GPIO port where the button is connected.
 * @param pin Number of the pin where the button is connected.
 * @return Pointer to the initialized button object.
 */
button_InitTypeDef* button_Init(GPIO_T *port, unsigned long pin)
{
	/* Dynamically allocate memory for a new button object */
	button_InitTypeDef *button = (button_InitTypeDef *)malloc(sizeof(button_InitTypeDef));
	
	/* Set the button's GPIO port and pin */
	button->port = port;
	button->pin = pin;
	
	/* Set the GPIO mode to input for this button */
	GPIO_SetMode(port, pin, GPIO_MODE_INPUT);
	
	/* Return the pointer to the new button object */
	return button;
}

/**
 * @brief Deinitializes a button
 * @details This function is used to free the memory allocated for a button object.
 * @param button Pointer to the button object to be deinitialized.
 * @return None
 */
void button_DeInit(button_InitTypeDef *button)
{
	/* Freeing the memory allocated for the button */
	free(button);
}

/**
 * @brief Gets the status of a button
 * @details This function is used to get the status of a button, considering debounce and long press situations.
 * @param button Pointer to the button object.
 * @return 0 if a state change occurred and is processed; -1 if there's no significant change.
 */
int button_Get_Status(button_InitTypeDef *button)
{
	static int lastButtonState, buttonState;
	
	/* Reading the button state */
	buttonState = button_Read(button);
	
	/* Checking for button state change */
	if(buttonState != lastButtonState && buttonState)
	{
		/* Resetting timers and setting them for debounce and long press detection */
		SoftTimer_ResetTimer(TIMER_DEBOUNCE);
		SoftTimer_ResetTimer(TIMER_LONG_PRESS);
		
		SoftTimer_SetTimer(TIMER_DEBOUNCE, 100);
		SoftTimer_SetTimer(TIMER_LONG_PRESS, 3000);
		
		/* Updating the last button state */
		lastButtonState = buttonState;
		
		return 0;
	}
	else if(SoftTimer_GetTimerStatus(TIMER_LONG_PRESS))
	{
		/* Handling a long press event */
		SoftTimer_ResetTimer(TIMER_LONG_PRESS);
		SoftTimer_ResetTimer(TIMER_DEBOUNCE);
		
		/* Enqueues the long press event */
		enqueue(LONG_PRESS);
		
		/* Updating the last button state */
		lastButtonState = buttonState;
		return 0;
	}
	else if (SoftTimer_GetTimerStatus(TIMER_DEBOUNCE) && (!buttonState))
	{
		/* Handling a short press (debounce) event */
		SoftTimer_ResetTimer(TIMER_DEBOUNCE);
		
		/* Enqueues the short press event */
		enqueue(SHORT_PRESS);
		
		/* Updating the last button state */
		lastButtonState = buttonState;
		return 0;
	}
	
	/* Updating the last button state */
	lastButtonState = buttonState;
	return -1;
}

/**
 * @brief Reads the state of a button
 * @details This function reads the state of a button from the GPIO pin.
 * @param button Pointer to the button object.
 * @return State of the button. Returns 1 if button is pressed, 0 otherwise.
 */
int button_Read(button_InitTypeDef *button)
{
	/* Reading the state of the button from the GPIO pin */
	return !(GPIO_PIN_DATA(getPortNumber(button->port), getPinNumber(button->pin)));
}
