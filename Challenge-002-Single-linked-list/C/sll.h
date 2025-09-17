#ifndef SLL_H_
#define SLL_H_

struct Node
{
    void*        data;
    struct Node* next;
};
typedef struct Node Node_Type;

typedef struct
{
    Node_Type* head;
}List_Type;

typedef struct 
{
    int index;
}Data_Type;


extern void       List_CreateList        (List_Type** list);
extern void       List_InsertAtBeginning (List_Type*  list,void* data);
extern void       List_InsertAtEnd       (List_Type*  list,void* data);
extern void       List_InsertAfterNode   (List_Type*  list,void* prevData,void* data);
extern void       List_InsertAtIndex     (List_Type*  list,void* data,int index);
extern void       List_DeleteNode        (List_Type** list,void* data);
extern void       List_DeleteNodeAtIndex (List_Type** list,int index);
extern Node_Type* List_SearchNode        (List_Type*  list,void* data);
extern Node_Type* List_SearchNodeAtIndex (List_Type*  list,int index);
extern int        List_Size              (List_Type*  list);
extern void       List_Traverse          (List_Type*  list);
extern void       List_Delete            (List_Type** list);
extern void       List_IncrementalSort   (List_Type*  list);
extern void       List_DecrementalSort   (List_Type*  list);
extern void       List_Copy              (List_Type** destList,List_Type* srcList);
extern void       List_Concatenate       (List_Type*  list1,List_Type* list2);
extern void       List_ConcatenateAtList (List_Type** destList,List_Type* list1,List_Type* list2);
extern void       List_IncrementalMerge  (List_Type*  list1,List_Type* list2);
extern void       List_DecrementalMerge  (List_Type*  list1,List_Type* list2);
extern void       List_Swap              (List_Type** list1,List_Type** list2);
extern void       List_SwapNode          (List_Type*  list1,int data1,int data2);
extern void       List_AddData           (List_Type*  list,int data);
#endif
