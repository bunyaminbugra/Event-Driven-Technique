#ifndef LED_H
#define LED_H

#include "main.h"

/**/
#include <stdbool.h>

typedef struct
{
	GPIO_T *port;
	unsigned long pin;
} led_InitTypeDef;

typedef struct
{
	_Bool IsRunning;
	volatile _Bool IsFinish;
	unsigned int repeat;
	unsigned long onTime;
	unsigned long offTime;
	unsigned long Time;
} blink_Type;

led_InitTypeDef* led_Init(GPIO_T *port, unsigned long pin);
void led_DeInit(led_InitTypeDef *led);
void blink(led_InitTypeDef *led, int onTime, int repeat);
void short_press_state(led_InitTypeDef *led);
void long_press_state(led_InitTypeDef *led);
void led_SET(led_InitTypeDef *led);
void led_RESET(led_InitTypeDef *led);
void led_TOGGLE(led_InitTypeDef *led);
int getPortNumber(GPIO_T* port);
int getPinNumber(unsigned long u32PinMask);

#endif
