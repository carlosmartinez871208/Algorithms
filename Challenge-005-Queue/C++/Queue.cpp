#include "Queue.h"

void Queue::enqueue (func_ptr data)
{
    if(!isFull())
    {
        front+=1;
        items[front] = data;
    }
}

void Queue::dequeue (void)
{
    if(!isEmpty())
    {
        items[FRONT]();
        for(int i=FRONT;i<front;i++)
        {
            items[i] = items[i+1];
        }
        front-=1;
    }
}

void Queue::peak    (void)
{
    if(!isEmpty())
    {
        items[FRONT]();
    }
}

int Queue::isFull  (void)
{
    return (MAX_QUEUE_SIZE==front)?1:0;
}

int Queue::isEmpty (void)
{
    return (EMPTY==front)?1:0;
}