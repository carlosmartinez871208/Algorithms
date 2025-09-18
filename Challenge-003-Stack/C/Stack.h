#ifndef STACK_H_
#define STACK_H_

#include <stdlib.h>

#define MAX_STACK_SIZE  (100)
#define EMPTY           (-1)
#define FULL            (MAX_STACK_SIZE-1)
#define TOP             (0)

typedef void(*func_ptr)(void);

typedef struct
{
    func_ptr items[MAX_STACK_SIZE];
    int top;
}Stack_Type;

extern void init    (Stack_Type* Stack);
extern void push    (Stack_Type* Stack,func_ptr data);
extern void pop     (Stack_Type* Stack);
extern int  isFull  (Stack_Type* Stack);
extern int  isEmpty (Stack_Type* Stack);
extern void peak    (Stack_Type* Stack);

#endif
