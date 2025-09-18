#include <iostream>

#include "Stack.h"

void Stack::push    (func_ptr data){
    if(!isFull()){
        this->top+=1;
        this->items[this->top] = data;
    }
}

void Stack::pop     (void){
    if(!isEmpty()){
        this->items[this->top]();
        this->top-=1;
    }
}

int  Stack::isFull  (void){
    return (FULL==this->top)?1:0;
}

int  Stack::isEmpty (void){
    return (EMPTY==this->top)?1:0;
}

void Stack::peak    (void){
     if(!isEmpty()){
        this->items[this->top]();
    }
}