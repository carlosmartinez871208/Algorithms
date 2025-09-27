#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

typedef void(*func_ptr)(void);

struct Node{
    func_ptr     data;
    struct Node* next;
    Node (func_ptr val): data(val),next(nullptr){}
};

typedef struct Node Node_Type;

class Queue {
    public:
        Node* Top;
        Queue ():Top(nullptr){}
        ~Queue();
        void enqueue    (func_ptr data);
        void dequeue    (void);
        void peak       (void);
};

#endif
