/* Template for C++ project */
#include <iostream>

#include "Queue.h"

void Temperature_Get(void)
{
    std::cout << "27 degrees Celsius" << std::endl;
}

void Pressure_Get(void)
{
    std::cout << "1013 hPa" << std::endl;
}

void Humidity_Get(void)
{
    std::cout << "40 %" << std::endl;
}

int main (int argc, char** argv)
{
    Queue data;
    data.enqueue(&Temperature_Get);
    data.enqueue(&Pressure_Get);
    data.dequeue();
    data.dequeue();
    data.enqueue(&Humidity_Get);
    data.dequeue();
    data.peak();
    return EXIT_SUCCESS;
}
