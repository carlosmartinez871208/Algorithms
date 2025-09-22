#ifndef STACK_H_
#define STACK_H_

#define MAX_STACK_SIZE  (100)
#define EMPTY           (-1)
#define FULL            (MAX_STACK_SIZE-1)
#define TOP             (0)

typedef void(*func_ptr)(void);

struct Node{
    func_ptr     data;
    struct Node* next;
    Node (func_ptr val): data(val),next(nullptr){}
};

typedef struct Node Node_Type;

class Stack {
    public:
        Node* Top;
        Stack ():Top(nullptr){}
        ~Stack();
        void push    (func_ptr data);
        void pop     (void);
        void peak    (void);
};

#endif
