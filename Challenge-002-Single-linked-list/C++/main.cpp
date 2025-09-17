/* Template for C++ project */
#include <iostream>

#include "sll.h"

int main (int argc, char** argv)
{
    SingleLinkedList ListA;
    SingleLinkedList ListB;
    ListA.InsertAtBeginning(5);
    ListA.InsertAtBeginning(6);
    ListA.InsertAtIndex(5,9);
    ListA.InsertAtEnd(7);
    ListA.Traverse();
    ListB.Copy(ListA.head);
    ListB.Traverse();
    return EXIT_SUCCESS;
}
