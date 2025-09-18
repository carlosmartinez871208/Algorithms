/* Template for C program. */
#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

void read_temperature ();
void turn_off_led     ();
void system_info      ();

int main(void)
{
    Stack_Type Data;
    init(&Data);
    push(&Data,&read_temperature);
    push(&Data,&turn_off_led);
    pop(&Data);
    pop(&Data);
    push(&Data,&system_info);
    pop(&Data);
    return 0;
}

void read_temperature ()
{
    printf("Temperature is: 27.6 Celsius\n");
}

void turn_off_led     ()
{
    printf("LED is off now\n");
}

void system_info      ()
{
    printf("System is working properly\n");
}