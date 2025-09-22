#include <iostream>

#include "Stack.h"

Stack::~Stack(){
    Node_Type* temp = Top;
    while(nullptr!=temp)
    {
        temp = temp->next;
        delete Top;
        Top = temp;
    }
}

void Stack::push    (func_ptr data){
    Node_Type* newNode = new Node_Type(data);
    newNode->next = Top;
    Top = newNode;
}

void Stack::pop     (void){
    Node_Type* aux=NULL;
    if(nullptr!=Top)
    {
        aux = Top;
        Top = aux->next;
        aux->data();
        delete aux;
        aux=NULL;
    }
}

void Stack::peak    (void){
    if(nullptr!=Top)
    {
        Top->data();
    }
}