/** 
  * @file: button.h
  * @author: Bünyamin Buðra Korkmazer
  * @date: June 18, 2023
  * @version: 1.0
  *
  * @brief: Header file for button handling mechanism.
  *
  * @details: This file contains the definitions of the functions and structure for a 
  * button handling mechanism, considering debounce and long press situations.
  *
  * Revision History: 
  * - 1.0.0 (June 18, 2023): Initial release.
  */

#ifndef BUTTON_H
#define BUTTON_H

#include "main.h"
#include "eventDriven.h"

/* The structure definition for a button. Contains the port and pin information. */
typedef struct
{
	GPIO_T *port;		/* GPIO port for the button */
	unsigned long pin;		/* Pin number for the button */
} button_InitTypeDef;

/**
  * @section   Function Prototypes
  * @brief     This section includes function prototypes.
  */
button_InitTypeDef* button_Init(GPIO_T *port, unsigned long pin);
void button_DeInit(button_InitTypeDef *button);
int button_Get_Status(button_InitTypeDef *button);
int button_Read(button_InitTypeDef *button);

#endif
