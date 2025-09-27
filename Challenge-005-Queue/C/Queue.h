#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdlib.h>

#define MAX_QUEUE_SIZE  (100)
#define EMPTY           (-1)
#define FRONT           (0)
#define FULL            (MAX_QUEUE_SIZE-1)

typedef void(*func_ptr)(void);

typedef struct
{
    func_ptr items[MAX_QUEUE_SIZE];
    int front;
}Queue_Type;

void Queue_init    (Queue_Type* Queue);
int  Queue_isEmpty (Queue_Type* Queue);
int  Queue_isFull  (Queue_Type* Queue);
void Queue_enqueue (Queue_Type* Queue,func_ptr data);
void Queue_dequeue (Queue_Type* Queue);
void Queue_peak    (Queue_Type* Queue);

#endif
