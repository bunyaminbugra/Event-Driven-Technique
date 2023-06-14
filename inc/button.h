#ifndef BUTTON_H
#define BUTTON_H

#include "main.h"
#include "eventDriven.h"

typedef struct
{
	GPIO_T *port;
	unsigned long pin;
	volatile uint32_t buttonPin;
} button_InitTypeDef;

void button_Init(GPIO_T *port, unsigned long pin, int portNumber, int pinNumber);
void button_DeInit(button_InitTypeDef *button);
int button_Get_Status(button_InitTypeDef *button);

#endif
