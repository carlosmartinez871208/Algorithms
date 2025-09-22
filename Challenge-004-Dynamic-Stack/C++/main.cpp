/* Template for C++ project */
#include <iostream>

#include "Stack.h"

void read_temperature ();
void turn_off_led     ();
void system_info      ();

int main (int argc, char** argv)
{
    Stack ipc;
    ipc.push(&read_temperature);
    ipc.push(&turn_off_led);
    ipc.push(&system_info);
    ipc.pop();
    ipc.pop();
    ipc.pop();
    ipc.pop();
    return EXIT_SUCCESS;
}

void read_temperature (){
    std::cout<<"Temperature is: 27.6 Celsius"<<std::endl;
}

void turn_off_led     (){
    std::cout<<"LED is off now"<<std::endl;
}

void system_info      (){
    std::cout<<"System is working properly"<<std::endl;
}