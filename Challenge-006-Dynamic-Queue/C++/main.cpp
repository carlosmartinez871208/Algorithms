/* Template for C++ project */
#include <iostream>

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

int main (int argc, char** argv)
{
    Queue myQueue;
    myQueue.enqueue(Temperature_Get);
    myQueue.enqueue(Pressure_Get);
    myQueue.enqueue(Humidity_Get);
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    return EXIT_SUCCESS;
}
