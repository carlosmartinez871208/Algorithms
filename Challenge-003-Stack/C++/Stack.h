#ifndef STACK_H_
#define STACK_H_

#define MAX_STACK_SIZE  (100)
#define EMPTY           (-1)
#define FULL            (MAX_STACK_SIZE-1)
#define TOP             (0)

typedef void(*func_ptr)(void);

class Stack {
    private:
        func_ptr items[MAX_STACK_SIZE];
        int top;
    public:
        Stack():top(-1){}
        void push    (func_ptr data);
        void pop     (void);
        int  isFull  (void);
        int  isEmpty (void);
        void peak    (void);
};

#endif
