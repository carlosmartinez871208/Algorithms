#include "Queue.h"

void Queue_init(Queue_Type* Queue)
{
    Queue->front = EMPTY;
}

int Queue_isEmpty(Queue_Type* Queue)
{
    return (EMPTY==Queue->front)?1:0;
}

int Queue_isFull(Queue_Type* Queue)
{
    return (MAX_QUEUE_SIZE==Queue->front)?1:0;
}

void Queue_enqueue (Queue_Type* Queue,func_ptr data)
{
    if(!Queue_isFull(Queue))
    {
        Queue->front+=1;
        Queue->items[Queue->front] = data;
    }
}

void Queue_dequeue (Queue_Type* Queue)
{
    if(!Queue_isEmpty(Queue))
    {
        Queue->items[FRONT]();
        for(int i=FRONT;i<Queue->front;i++)
        {
            Queue->items[i] = Queue->items[i+1];
        }
        Queue->front-=1;
    }
}

void Queue_peak    (Queue_Type* Queue)
{
    if(!Queue_isEmpty(Queue))
    {
        Queue->items[FRONT]();
    }
}