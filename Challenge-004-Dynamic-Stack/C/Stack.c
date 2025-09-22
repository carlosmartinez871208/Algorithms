#include "Stack.h"

void init    (Stack_Type** Stack)
{
    Stack_Type* temp = (Stack_Type*)malloc(sizeof(Stack_Type));
    temp->Top = NULL;
    *Stack = temp;
}

void push    (Stack_Type* Stack,func_ptr data)
{
    Node_Type* aux=NULL;
    if(NULL!=Stack)
    {
        aux = (Node_Type*)malloc(sizeof(Node_Type));
        aux->data = data;
        aux->next = Stack->Top;
        Stack->Top = aux;
    }
}

void pop     (Stack_Type* Stack)
{
    Node_Type* aux=NULL;
    if(NULL!=Stack)
    {
        if(NULL!=Stack->Top)
        {
            aux = Stack->Top;
            Stack->Top = aux->next;
            aux->data();
            free(aux);
            aux=NULL;
        }
    }
}

void peak    (Stack_Type* Stack)
{
    if(NULL!=Stack)
    {
        if(NULL!=Stack->Top)
        {
            Stack->Top->data();
        }
    }
}

void delete  (Stack_Type** Stack)
{
     Node_Type* aux=NULL;
    if(NULL!=*Stack)
    {
        while(NULL!=(**Stack).Top)
        {
            aux = (**Stack).Top;
            free((**Stack).Top);
            (**Stack).Top = aux;
        }
        free(*Stack);
        *Stack = NULL;
    }
}