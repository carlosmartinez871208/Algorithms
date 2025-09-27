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
    Queue_Type Data;
    Queue_init(&Data);
    Queue_enqueue(&Data,&Temperature_Get);
    Queue_enqueue(&Data,&Pressure_Get);
    Queue_dequeue(&Data);
    Queue_dequeue(&Data);
    Queue_enqueue(&Data,&Humidity_Get);
    Queue_dequeue(&Data);
    Queue_peak(&Data);
    return 0;
}