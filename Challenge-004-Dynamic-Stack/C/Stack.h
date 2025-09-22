#ifndef STACK_H_
#define STACK_H_

#include <stdlib.h>

typedef void(*func_ptr)(void);

struct Node
{
    func_ptr     data;
    struct Node* next;
};
typedef struct Node Node_Type;

typedef struct
{
    Node_Type* Top;
}Stack_Type;

extern void init    (Stack_Type** Stack);
extern void push    (Stack_Type* Stack,func_ptr data);
extern void pop     (Stack_Type* Stack);
extern void peak    (Stack_Type* Stack);
extern void delete  (Stack_Type** Stack);

#endif
