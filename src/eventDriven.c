#include "main.h"

struct Event *front = NULL;
struct Event *rear = NULL;

int enqueue(int type)
{
    /* Queue is empty */
    if (front == NULL)
    {
        struct Event *new = (struct Event *)malloc(sizeof(struct Event));
        new->type = type;
        new->next = NULL;

        front = rear = new;
    }
    else
    {
        struct Event *new = (struct Event *)malloc(sizeof(struct Event));
        new->type = type;
        new->next = NULL;

        rear->next = new;
        rear = new;
    }
    
	return 0;
}

/* Dequeue */
int dequeue(struct Event *event)
{
	struct Event *temp;
	
    if (front == NULL)
    {
        printf("Queue is empty!");
        return -1;
    }

    temp = front;
	event->type = front->type;
    front = front->next;
    free(temp);

    return 0;
}
