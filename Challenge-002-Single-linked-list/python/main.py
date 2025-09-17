#!python3
# Template for Python script
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SingleLinkedList:
    def __init__(self):
        self.head = None

    def InsertAtBeginning(self, data):
        node = Node(data)
        node.next = self.head
        self.head = node

    def InsertAtEnd(self, data):
        node = Node(data)
        if not self.head:
            self.head = node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = node

    def DeleteNodeAtIndex (self,index):
        temp = self.head
        counter = 2
        if self.head:
            if index==0 and index==1:
                temp = temp.next
                self.head = temp
            else:
                while temp.next.next and counter<index:
                    temp = temp.next
                    counter+=1
                aux = temp.next
                temp.next = aux.next

    def Traverse(self):
        current = self.head
        result = []
        while current:
            result.append(current.data)
            current = current.next
        print(result)

if __name__ == "__main__":
    ListA = SingleLinkedList()
    ListA.InsertAtBeginning(3)
    ListA.InsertAtEnd(2)
    ListA.InsertAtEnd(4)
    ListA.InsertAtBeginning(5)
    ListA.DeleteNodeAtIndex(3)
    ListA.Traverse()

