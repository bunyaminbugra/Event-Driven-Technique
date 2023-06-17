#ifndef EVENT_DRIVEN_H
#define EVENT_DRIVEN_H

typedef enum
{
	SHORT_PRESS,
	LONG_PRESS
} Event_Type;

typedef enum
{
	LED_ON,
	LED_OFF
} LED_state;

struct Event
{
	int type;
	Event_Type mode;
	LED_state led_state;
	unsigned long Time;
	struct Event *next;
};

int enqueue(int type);
int dequeue(struct Event *event);

#endif
