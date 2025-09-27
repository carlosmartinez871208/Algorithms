#ifndef QUEUE_H_
#define QUEUE_H_

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
}Queue_Type;

extern void Queue_init    (Queue_Type** Queue);
extern void Queue_enqueue (Queue_Type*  Queue,func_ptr data);
extern void Queue_dequeue (Queue_Type*  Queue);
extern void Queue_peak    (Queue_Type*  Queue);
extern void Queue_delete  (Queue_Type** Queue);

#endif
