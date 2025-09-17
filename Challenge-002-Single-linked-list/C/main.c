/* Template for C program. */
#include <stdio.h>
#include <stdlib.h>

#include "sll.h"

int main(void)
{
    List_Type* ListA = NULL;
    List_Type* ListB = NULL;
    List_CreateList (&ListA);
    List_AddData (ListA,5);
    List_AddData (ListA,6);
    List_AddData (ListA,3);
    List_AddData (ListA,7);
    List_AddData (ListA,2);
    List_CreateList (&ListB);
    List_AddData (ListB,9);
    List_AddData (ListB,4);
    List_AddData (ListB,1);
    List_AddData (ListB,0);
    List_AddData (ListB,8);
    List_Traverse (ListA);
    List_Traverse (ListB);
    List_Swap (&ListA,&ListB);
    List_Traverse (ListA);
    List_Traverse (ListB);
    List_DeleteNodeAtIndex (&ListA,5);
    List_DeleteNodeAtIndex (&ListB,5);
    List_Traverse (ListA);
    List_Traverse (ListB);
    List_DecrementalMerge (ListA,ListB);
    List_Traverse (ListA);
    List_SwapNode (ListA,7,8);
    List_Traverse (ListA);
    List_Delete (&ListA);
    List_Delete (&ListB);
    return 0;
}