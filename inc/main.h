#ifndef MAIN_H
#define MAIN_H

/* Include the standard C library for input-output operations */
#include <stdio.h>

/* Include the header file for the NuMicro MCU series */
#include "NuMicro.h"

/* Include the header file specific to the M031 series of the NuMicro MCU */
#include "M031Series.h"

/**/
#include "led.h"

/**/
#include "button.h"

/**/
#include "utils.h"

/**/
#include <stdint.h>

/**/
#include <stdbool.h>

/**/
#include <stdlib.h>

/**
  * @section   Macro Definitions
  * @brief     This section includes macro definitions.
  */
  
#define	HIGH	1
#define	LOW	0
  
#define LED_GREEN	PB14
#define LED_GREEN_PORT	PB
#define LED_GREEN_PIN	BIT14

#define LED_GREEN_ON	(LED_GREEN = HIGH)
#define LED_GREEN_OFF	(LED_GREEN = LOW)

#define BUTTON	PB15
#define	BUTTON_PORT	PB
#define	BUTTON_PIN	BIT15

typedef enum
{
	NONE,
	SHORT_PREES,
	LONG_PRESS
} Event_Type;

struct Event
{
	int type;
	struct Event *next;
};

struct Event *front = NULL;
struct Event *rear = NULL;

#endif
