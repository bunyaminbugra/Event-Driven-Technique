/**
  * @file: main.c
  * @author: Bünyamin Bugra Korkmazer
  * @date: June 18, 2023
  * @version: 1.0
  *
  * @brief: Source file for the event queue and event initialization operations in the application.
  * 
  * @details: This file defines the functions for handling events which includes enqueuing, dequeuing events and event initialization. 
  *           Events are structured as linked list nodes. Include this source file in any other source file where these functions are needed.
  *
  *  Revision History: 
  * - 1.0.0 (June 18, 2023): Initial release.
  */

#include "main.h"

/* Front and rear pointers for our event queue */
struct Event *front = NULL;
struct Event *rear = NULL;

/**
  * @brief   Enqueues a new event to the event queue.
  * @details This function creates a new event node with a specified type and adds it to the event queue.
  * @param   type The type of the event to enqueue.
  * @return  0 on success.
  */
int enqueue(Event_Type type)
{
    /* If the queue is empty, we create the first node */
    if (front == NULL)
    {
        struct Event *new = (struct Event *)malloc(sizeof(struct Event));
        new->mode = type;
        new->next = NULL;

		/* Set front and rear to the new node */
        front = rear = new;
    }
    else /* If queue is not empty, we add the node to the end */
    {
        struct Event *new = (struct Event *)malloc(sizeof(struct Event));
        new->mode = type;
        new->next = NULL;

        rear->next = new;		// Attach new node to end of queue
        rear = new;		// Make new node the rear
    }
    
	return 0;
}

/**
  * @brief   Dequeues an event from the event queue.
  * @details This function removes the first event in the queue and returns its type. 
  *          The memory allocated for the dequeued event is freed.
  * @param   event Pointer to the event to be dequeued.
  * @return  Type of the dequeued event, or NONE if the queue is empty.
  */
Event_Type dequeue(struct Event *event)
{
	static struct Event *temp;
	Event_Type returnVal;
	
	/* If queue is empty, return NONE */
    if (front == NULL)
    {
        return NONE;
    }

	/* If queue is not empty, remove the front event and adjust front */
    temp = front;
	returnVal = front->mode;
    front = front->next;
    free(temp);

    return returnVal;
}

/**
  * @brief   Initializes an event.
  * @details This function sets up the initial values for an event structure.
  * @param   event Pointer to the event to be initialized.
  * @return  None
  */
void event_Init(struct Event *event)
{
	event->Time = 1000;		// Set time
	event->mode = SHORT_PRESS;		// Set mode
	event->led_state = LED_ON;		// Set LED state
	event->state_Counter = 0;		// Initialize state counter
}
