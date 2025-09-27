#ifndef QUEUE_H_
#define QUEUE_H_

#define MAX_QUEUE_SIZE  (100)
#define EMPTY           (-1)
#define FRONT           (0)
#define FULL            (MAX_QUEUE_SIZE-1)

typedef void(*func_ptr)(void);

class Queue {
    private:
        func_ptr items[MAX_QUEUE_SIZE];
        int front;
    public:
        Queue():front(-1){}
        void enqueue (func_ptr data);
        void dequeue (void);
        int  isFull  (void);
        int  isEmpty (void);
        void peak    (void);
};


#endif
