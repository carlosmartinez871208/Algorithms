#include <iostream>

#include "sll.h"

SingleLinkedList::SingleLinkedList(){
    head = nullptr;
}

SingleLinkedList::~SingleLinkedList(){
    Node_Type* temp = head;
    while(nullptr!=temp)
    {
        temp = temp->next;
        delete head;
        head = temp;
    }
}

void SingleLinkedList::InsertAtBeginning(int data){
    Node_Type* node = new Node_Type(data);
    node->next = head;
    head = node;
}

void SingleLinkedList::InsertAtEnd (int data){
    Node_Type* node = new Node_Type(data);
    Node_Type* temp = head;
    if(nullptr != temp){
        while(nullptr != temp->next){
            temp = temp->next;
        }
        temp->next = node;
    }else{
        head = node;
    }
}

void SingleLinkedList::InsertAtIndex (int index,int data){
    Node_Type* node = new Node_Type(data);
    Node_Type* temp = head;
    int counter = 2;
    if(nullptr != temp){
        if(0==index || 1==index){
            node->next = head;
            head = node;
        }else{
            while(counter<index && nullptr!=temp->next){
                counter+=1;
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
        }
    }else{
        head = node;
    }
}

void SingleLinkedList::DeleteNodeAtIndex (int index){
    Node_Type* temp = head;
    Node_Type* aux  = nullptr;
    int counter = 2;
    if(nullptr != head){
        if(0==index || 1==index){
            temp = temp->next;
            delete head;
            head = temp;
        }else{
            while(counter<index && nullptr!=temp->next->next){
                counter+=1;
                temp = temp->next;
            }
            aux = temp->next;
            temp->next = aux->next;
            delete aux;
        }
    }
}

void SingleLinkedList::SwapNodes (int index1,int index2)
{
    Node_Type* temp1 = head;
    Node_Type* temp2 = head;
    Node_Type* aux = nullptr;
    int counter = 2;
    if(nullptr != head){
        if(index1>index2){
            index2=index1+index2;
            index1=index2-index1;
            index2=index2-index1;
        }
        if(0==index1 || 1==index1){
            while(nullptr!=temp1->next && index2!=counter){
                counter += 1;
                temp1 = temp1->next;
            }
            aux = head;
            head = temp1->next;
            temp1->next = aux;
            temp1 = temp1->next;
            aux = head->next;
            head->next = temp1->next;
            temp1->next = aux;
        }else if(index1!=index2){
            while(nullptr!=temp1->next && index1!=counter){
                counter += 1;
                temp1 = temp1->next;
            }
            counter = 2;
            while(nullptr!=temp2->next && index2!=counter){
                counter += 1;
                temp2 = temp2->next;
            }
            aux = temp1->next;
            temp1->next = temp2->next;
            temp2->next = aux;
            temp1 = temp1->next;
            temp2 = temp2->next;
            aux = temp1->next;
            temp1->next = temp2->next;
            temp2->next = aux;
        }
    }
}

void SingleLinkedList::DecrementalSort (void){
    Node_Type* temp = nullptr;
    Node_Type* aux  = nullptr;
    int list_size   = Size()-1;
    if(nullptr != head){
        for(int i=0;i<list_size;i++){
            for(int j=0;j<list_size-i;j++){
                if(0==j){
                    temp=head;
                    aux=temp->next;
                    if(temp->data < aux->data){
                        temp->next=aux->next;
                        aux->next=temp;
                        head = aux;
                    }else{
                        aux=head;
                    }
                }else if(j>0){
                    temp=aux;
                    aux=temp->next;
                    if(temp->next->data < aux->next->data){
                        temp->next=aux->next;
                        temp=aux;
                        aux=temp->next;
                        temp->next=aux->next;
                        aux->next = temp;
                    }
                }
            }
        }
    }
}

void SingleLinkedList::IncrementalSort (void){
    Node_Type* temp = nullptr;
    Node_Type* aux  = nullptr;
    int list_size   = Size()-1;
    if(nullptr != head){
        for(int i=0;i<list_size;i++){
            for(int j=0;j<list_size-i;j++){
                if(0==j){
                    temp=head;
                    aux=temp->next;
                    if(temp->data > aux->data){
                        temp->next=aux->next;
                        aux->next=temp;
                        head = aux;
                    }else{
                        aux=head;
                    }
                }else if(j>0){
                    temp=aux;
                    aux=temp->next;
                    if(temp->next->data > aux->next->data){
                        temp->next=aux->next;
                        temp=aux;
                        aux=temp->next;
                        temp->next=aux->next;
                        aux->next = temp;
                    }
                }
            }
        }
    }
}

void SingleLinkedList::Concatenate (Node_Type* list){
    Node_Type* temp = list;
    if(nullptr!=list){
        if(nullptr!=head){
            while(nullptr!=temp){
                InsertAtEnd(temp->data);
                temp = temp->next;
            }
        }
    }
}

void SingleLinkedList::DecrementalMerge (Node_Type* list){
    Concatenate(list);
    DecrementalSort();
}

void SingleLinkedList::IncrementalMerge (Node_Type* list){
    Concatenate(list);
    IncrementalSort();
}

void SingleLinkedList::Copy (Node_Type* list){
    Node_Type* temp = list;
    if(nullptr == head){
        if(nullptr != list){
            while(nullptr != temp){
                InsertAtEnd(temp->data);
                temp = temp->next;
            }
        }
    }
}

void SingleLinkedList::Traverse(void){
    Node* temp = head;
    while(nullptr != temp){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

int SingleLinkedList::Size (void){
    Node* temp = head;
    int counter = 0;
    while(nullptr != temp)
    {
        temp=temp->next;
        counter+=1;
    }
    return counter;
}

