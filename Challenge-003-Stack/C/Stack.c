#include "Stack.h"

void init    (Stack_Type* Stack)
{
    Stack->top = EMPTY;
}

void push    (Stack_Type* Stack,func_ptr data)
{
    if(!isFull(Stack))
    {
        Stack->top+=1;
        Stack->items[Stack->top] = data;
    }
}

void pop     (Stack_Type* Stack)
{
    if(!isEmpty(Stack))
    {
        Stack->items[Stack->top]();
        Stack->top-=1;
    }
}

int  isFull  (Stack_Type* Stack)
{
    return (FULL==Stack->top)?1:0;
}

int  isEmpty (Stack_Type* Stack)
{
    return (EMPTY==Stack->top)?1:0;
}

void peak    (Stack_Type* Stack)
{
    if(!isEmpty(Stack))
    {
        Stack->items[Stack->top]();
    }
}