#ifndef BUTTON_H
#define BUTTON_H

#include "main.h"
#include "eventDriven.h"

typedef struct
{
	GPIO_T *port;
	unsigned long pin;
} button_InitTypeDef;

button_InitTypeDef* button_Init(GPIO_T *port, unsigned long pin);
void button_DeInit(button_InitTypeDef *button);
int button_Get_Status(button_InitTypeDef *button, led_InitTypeDef *led);
int button_Read(button_InitTypeDef *button);

#endif
