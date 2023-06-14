#ifndef EVENT_DRIVEN_H
#define EVENT_DRIVEN_H

typedef enum
{
	NONE_EVENT,
	SHORT_PREES,
	LONG_PRESS
} Event_Type;

struct Event
{
	int type;
	struct Event *next;
};

int enqueue(int type);
int dequeue(struct Event *event);

#endif
