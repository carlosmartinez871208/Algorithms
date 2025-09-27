/* Template for C program. */
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

void Temperature_Get(void)
{
    printf("27 degrees Celsius\n");
}

void Pressure_Get(void)
{
    printf("1013 hPa\n");
}

void Humidity_Get(void)
{
    printf("40 %%\n");
}

int main(void)
{
    Queue_Type* Queue = NULL;
    Queue_init(&Queue);
    Queue_enqueue(Queue, Temperature_Get);
    Queue_enqueue(Queue, Pressure_Get);
    Queue_enqueue(Queue, Humidity_Get);
    Queue_dequeue(Queue);
    Queue_dequeue(Queue);
    Queue_dequeue(Queue);
    Queue_delete(&Queue);
    return 0;
}