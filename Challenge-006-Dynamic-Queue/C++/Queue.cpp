#include "Queue.h"

Queue::~Queue(){
    Node_Type* temp = Top;
    while(nullptr!=temp)
    {
        temp = temp->next;
        delete Top;
        Top = temp;
    }
}

void Queue::enqueue    (func_ptr data){
    Node_Type* temp = new Node_Type(data);
    Node_Type* aux = nullptr;
    if(nullptr==Top)
    {
        Top = temp;
    }
    else
    {
        aux = Top;
        while(nullptr!=aux->next)
        {
            aux = aux->next;
        }
        aux->next = temp;
    }
}

void Queue::dequeue    (void){
    Node_Type* aux=NULL;
    if(nullptr!=Top)
    {
        aux = Top;
        Top = aux->next;
        aux->data();
        delete aux;
        aux = nullptr;
    }
}

void Queue::peak       (void){
    if(nullptr!=Top)
    {
        Top->data();
    }
}
