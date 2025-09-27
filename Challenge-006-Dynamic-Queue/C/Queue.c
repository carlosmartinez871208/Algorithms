#include "Queue.h"

void Queue_init    (Queue_Type** Queue)
{
    *Queue = (Queue_Type*)malloc(sizeof(Queue_Type));
    (*Queue)->Top = NULL;
}

void Queue_enqueue (Queue_Type* Queue,func_ptr data)
{
    Node_Type* aux = NULL;
    Node_Type* temp = NULL;
    if(NULL!=Queue)
    {
        aux = (Node_Type*)malloc(sizeof(Node_Type));
        aux->data = data;
        aux->next = NULL;
        temp = Queue->Top;
        if(NULL==temp)
        {
            Queue->Top = aux;
        }
        else
        {
            while(NULL!=temp->next)
            {
                temp = temp->next;
            }
            temp->next = aux;
        }
    }
}

void Queue_dequeue (Queue_Type* Queue)
{
    Node_Type* aux=NULL;
    if(NULL!=Queue)
    {
        if(NULL!=Queue->Top)
        {
            aux = Queue->Top;
            Queue->Top = aux->next;
            aux->data();
            free(aux);
            aux=NULL;
        }
    }
}

void Queue_peak    (Queue_Type* Queue)
{
    if(NULL!=Queue)
    {
        if(NULL!=Queue->Top)
        {
            Queue->Top->data();
        }
    }
}

void Queue_delete  (Queue_Type** Queue)
{
     Node_Type* aux=NULL;
    if(NULL!=Queue)
    {
        while(NULL!=(**Queue).Top)
        {
            aux = (**Queue).Top->next;
            free((**Queue).Top);
            (**Queue).Top = aux;
        }
        free(*Queue);
        *Queue = NULL;
    }
}