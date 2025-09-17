#include <stdio.h>
#include <stdlib.h>

#include "sll.h"

static void List_CreateNode (Node_Type** node,void* data);

void List_CreateList (List_Type** list)
{
    List_Type* temp = (List_Type*)malloc(sizeof(List_Type));
    temp->head = NULL;
    *list = temp;
}

void List_CreateNode (Node_Type** node,void* data)
{
    Node_Type* temp = (Node_Type*)malloc(sizeof(Node_Type));
    temp->next = NULL;
    *node = temp;
}

void List_InsertAtBeginning (List_Type* list,void* data)
{
    Node_Type* node = NULL;
    if(NULL != list)
    {
        List_CreateNode(&node,data);
        node->data = data;
        node->next = list->head;
        list->head = node;
    }
}

void List_InsertAtEnd (List_Type* list,void* data)
{
    Node_Type* node = NULL;
    Node_Type* temp = NULL;
    if(NULL != list)
    {
        temp = list->head;
        List_CreateNode(&node,data);
        node->data = data;
        if(NULL==temp)
        {
            list->head = node;
        }
        else
        {
            while(NULL != temp->next)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
    }
}

void List_InsertAfterNode   (List_Type*  list,void* prevData,void* data)
{
    Node_Type* node = NULL;
    Node_Type* temp = NULL;
    if(NULL!=list)
    {
        temp = list->head;
        List_CreateNode(&node,data);
        node->data = data;
        if(NULL==temp)
        {
            list->head = node;
        }
        else
        {
            while(prevData!=temp->data && NULL!=temp->next)
            {
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
        }
    }
}

void List_InsertAtIndex     (List_Type*  list,void* data,int index)
{
    Node_Type* node = NULL;
    Node_Type* temp = NULL;
    int counter = 2;
    if(NULL != list)
    {
        temp = list->head;
        List_CreateNode(&node,data);
        node->data = data;
        if(NULL==temp)
        {
            list->head = node;
        }
        else if(0==index || 1==index)
        {
            node->next = list->head;
            list->head = node;
        }
        else
        {
            while(counter<index && NULL!=temp->next)
            {
                counter+=1;
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
        }
    }
}

void List_DeleteNode (List_Type**  list,void* data)
{
    Node_Type* temp = NULL;
    Node_Type* aux  = NULL;
    if(NULL != list)
    {
        temp = (**list).head;
        if(NULL != temp)
        {
            if(data == temp->data)
            {
                aux = temp->next;
                (**list).head = aux;
                free(temp->data);
                free(temp);
                temp=NULL;
            }
            else
            {
                while(data != temp->next->data)
                {
                    temp = temp->next;
                }
                aux = temp->next;
                temp->next = aux->next;
                free(aux->data);
                free(aux);
                aux=NULL;
            }
        }
    }
}

void List_DeleteNodeAtIndex (List_Type**  list,int index)
{
    Node_Type* temp = NULL;
    Node_Type* aux  = NULL;
    int counter=2;
    if(NULL != list)
    {
        temp = (**list).head;
        if(NULL != temp)
        {
            if(0==index || 1==index)
            {
                aux = temp->next;
                (**list).head = aux;
                free(temp->data);
                free(temp);
                temp=NULL;
            }
            else
            {
                while(counter<index && NULL!=temp->next->next)
                {
                    counter+=1;
                    temp = temp->next;
                }
                aux = temp->next;
                temp->next = aux->next;
                free(aux->data);
                free(aux);
                aux=NULL;
            }
        }
    }
}

Node_Type* List_SearchNode (List_Type*  list,void* data)
{
    Node_Type* temp = NULL;
    if(NULL != list)
    {
        temp = list->head;
        while(NULL!=temp && data!=temp->data)
        {
            temp = temp->next;
        }
    }
    return temp;
}

Node_Type* List_SearchNodeAtIndex (List_Type*  list,int index)
{
    Node_Type* temp = NULL;
    int counter=1;
    if(NULL != list)
    {
        temp = list->head;
        while(NULL!=temp && counter<index)
        {
            temp = temp->next;
            counter+=1;
        }
    }
    return temp;
}

void List_Traverse (List_Type* list)
{
    Node_Type* temp = NULL;
    if(NULL != list)
    {
        temp = list->head;
        while(NULL != temp)
        {
            printf("%d ",*(int*)temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int List_Size (List_Type* list)
{
    Node_Type* temp = NULL;
    int size = 0;
    if(NULL != list)
    {
        temp = list->head;
        while(NULL != temp)
        {
            temp = temp->next;
            size += 1;
        }
    }
    return size;
}

void List_Delete (List_Type** list)
{
    Node_Type* temp = NULL;
    if(NULL != list)
    {
        while(NULL != (**list).head)
        {
            temp = (**list).head->next;
            free((**list).head->data);
            free((**list).head);
            (**list).head = temp;
        }
        free(*list);
        *list = NULL;
    }
}

void List_IncrementalSort (List_Type* list) 
{
    Node_Type* temp = NULL;
    Node_Type* aux  = NULL;
    int list_size   = List_Size(list)-1;
    if(NULL != list)
    {
        for(int i=0;i<list_size;i++)
        {
            for(int j=0;j<list_size-i;j++)
            {
                if(0==j)
                {
                    temp=list->head;
                    aux=temp->next;
                    if(*(int*)temp->data > *(int*)aux->data)
                    {
                        temp->next=aux->next;
                        aux->next=temp;
                        list->head = aux;
                    }
                    else
                    {
                        aux=list->head;
                    }
                }
                else if(j>0)
                {
                    temp=aux;
                    aux=temp->next;
                    if(*(int*)temp->next->data > *(int*)aux->next->data)
                    {
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

void List_DecrementalSort (List_Type* list) 
{
    Node_Type* temp = NULL;
    Node_Type* aux  = NULL;
    int list_size   = List_Size(list)-1;
    if(NULL != list)
    {
        for(int i=0;i<list_size;i++)
        {
            for(int j=0;j<list_size-i;j++)
            {
                if(0==j)
                {
                    temp=list->head;
                    aux=temp->next;
                    if(*(int*)temp->data < *(int*)aux->data)
                    {
                        temp->next=aux->next;
                        aux->next=temp;
                        list->head = aux;
                    }
                    else
                    {
                        aux=list->head;
                    }
                }
                else if(j>0)
                {
                    temp=aux;
                    aux=temp->next;
                    if(*(int*)temp->next->data < *(int*)aux->next->data)
                    {
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

void List_Copy (List_Type** destList,List_Type* srcList)
{
    Node_Type* temp = NULL;
    Data_Type* data = NULL;
    if(NULL!= srcList)
    {
        if(NULL == *destList)
        {
            List_CreateList(destList);
        }
        temp = srcList->head;
        while(NULL != temp)
        {
            data = (Data_Type*)malloc(sizeof(Data_Type));
            data->index = *(int*)temp->data;
            List_InsertAtEnd(*destList,data);
            temp=temp->next;
        }
    }
}

void List_Concatenate (List_Type* list1,List_Type* list2)
{
    Node_Type* temp = NULL;
    Data_Type* data = NULL;
    if(NULL!=list1 && NULL!=list2)
    {
        temp = list2->head;
        while(NULL != temp)
        {
            data = (Data_Type*)malloc(sizeof(Data_Type));
            data->index = *(int*)temp->data;
            List_InsertAtEnd(list1,data);
            temp=temp->next;
        }
    }
}

void List_ConcatenateAtList (List_Type** destList,List_Type* list1,List_Type* list2)
{
    Node_Type* temp = NULL;
    Data_Type* data = NULL;
    if(NULL!=list1 && NULL!=list2)
    {
        if(NULL!=destList)
        {
            List_CreateList(destList);
        }
        temp=list1->head;
        while (NULL!=temp)
        {
            data = (Data_Type*)malloc(sizeof(Data_Type));
            data->index = *(int*)temp->data;
            List_InsertAtEnd(*destList,data);
            temp=temp->next;
        }
        temp=list2->head;
        while (NULL!=temp)
        {
            data = (Data_Type*)malloc(sizeof(Data_Type));
            data->index = *(int*)temp->data;
            List_InsertAtEnd(*destList,data);
            temp=temp->next;
        }
    }
}

void List_Swap (List_Type** list1,List_Type** list2)
{
    Node_Type* temp = NULL;
    if(NULL!=*list1 && NULL!=*list2)
    {
        temp = (**list1).head;
        (**list1).head = (**list2).head;
        (**list2).head = temp;
    }
}

void List_AddData (List_Type* list,int data)
{
    Data_Type* info = NULL;
    if(NULL!=list)
    {
        info = (Data_Type*)malloc(sizeof(Data_Type));
        info->index = data;
        List_InsertAtEnd(list,info);
    }
}

void List_IncrementalMerge  (List_Type* list1,List_Type* list2)
{
    List_Concatenate (list1,list2);
    List_IncrementalSort (list1);
}

void List_DecrementalMerge  (List_Type* list1,List_Type* list2)
{
    List_Concatenate (list1,list2);
    List_DecrementalSort (list1);
}

void List_SwapNode (List_Type* list,int data1,int data2)
{
    Node_Type* temp1  = NULL;
    Node_Type* temp2  = NULL;
    Node_Type* aux    = NULL;
    int node_ctr      = 2;
    if(NULL!=list)
    {
        temp1 = list->head;
        if(NULL!=temp1)
        {
            if (1==data1 || 0==data1)
            {
                temp2 = list->head;
                while(NULL!=temp2->next && data2!=node_ctr)
                {
                    node_ctr += 1;
                    temp2 = temp2->next;
                }
                aux = list->head;
                list->head = temp2->next;
                temp2->next = aux;
                temp2 = temp2->next;
                aux = list->head->next;
                list->head->next = temp2->next;
                temp2->next = aux;
            }
            else
            {
                while(NULL!=temp1->next && data1!=node_ctr)
                {
                    node_ctr += 1;
                    temp1 = temp1->next;
                }
                temp2 = list->head;
                node_ctr=2;
                while(NULL!=temp2->next && data2!=node_ctr)
                {
                    node_ctr += 1;
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
}