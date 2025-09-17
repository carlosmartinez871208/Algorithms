#ifndef SLL_H_
#define SLL_H_

struct Node
{
    int          data;
    struct Node* next;
    Node (int val): data(val),next(nullptr){}
};
typedef struct Node Node_Type;

class SingleLinkedList
{
    public:
        Node* head;
        SingleLinkedList();
        void InsertAtBeginning(int data);
        void InsertAtEnd (int data);
        void InsertAtIndex (int index,int data);
        void DeleteNodeAtIndex (int index);
        void SwapNodes (int index1,int index2);
        void DecrementalSort (void);
        void IncrementalSort (void);
        void Traverse(void);
        void Concatenate (Node_Type* list);
        void DecrementalMerge (Node_Type* list);
        void IncrementalMerge (Node_Type* list);
        void Copy (Node_Type* list);
        int  Size (void);
        ~SingleLinkedList();
};

#endif
