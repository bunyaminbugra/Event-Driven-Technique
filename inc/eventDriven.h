/**
  * @file: event_driven.h
  * @author: Bünyamin Bugra Korkmazer
  * @date: June 18, 2023
  * @version: 1.0
  *
  * @brief: Header file for the event management of the application.
  *
  * @details: This header file defines the Event structure, event types and LED states. 
  *           It also includes the function prototypes for event handling.
  *
  * Revision History: 
  * - 1.0.0 (June 18, 2023): Initial release.
  */

#ifndef EVENT_DRIVEN_H
#define EVENT_DRIVEN_H

/* Event Types */
typedef enum
{
	NONE,
	SHORT_PRESS,
	LONG_PRESS
} Event_Type;

/* LED States */
typedef enum
{
	LED_ON,
	LED_OFF
} LED_state;


/* Event Structure */
struct Event
{
	Event_Type mode;
	LED_state led_state;
	unsigned long Time;
	int state_Counter;
	struct Event *next;
};

/**
  * @section   Function Prototypes
  * @brief     This section includes function prototypes.
  */
int enqueue(Event_Type type);
Event_Type dequeue(struct Event *event);
void event_Init(struct Event *event);

#endif
