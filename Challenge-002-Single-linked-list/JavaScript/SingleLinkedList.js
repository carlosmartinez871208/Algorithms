class Node{
    constructor(value){
        this.value=value
        this.next = null
    }
}

class SingleLinkedList{
    constructor(){
        this.head = null
    }

    InsertAtBeginning(data){
        const node = new Node(data)
        node.next = this.head
        this.head = node
    }

    InsertAtEnd(data) {
        const node = new Node(data);
        if (!this.head) {
            this.head = node;
            return;
        }
        let current = this.head;
        while (current.next) {
            current = current.next;
        }
        current.next = node;
    }

    InsertAtIndex(index,data){
        const node = new Node(data);
        const temp = this.head;
        let counter = 2;
        if(this.head){
            if(0==index || 1==index){
                node.next = this.head;
                this.head = node;
            }else{
                while (temp.next && counter<index) {
                    counter+=1;
                    temp = temp.next;
                }
                node.next = temp.next;
                temp.next = node;
            }
        }else{
            this.head = node;
        }
    }

    DeleteNodeAtIndex(index){
        let temp = this.head;
        let counter = 2;
        if(this.head){
            if(0==index || 1==index){
                temp = temp.next;
                this.head = temp;
            }else{
                while (temp.next.next && counter<index) {
                    counter+=1;
                    temp = temp.next;
                }
                let aux = temp.next;
                temp.next = aux.next;
            }
        }
    }

    Traverse() {
        let current = this.head;
        let result = [];
        while (current) {
            result.push(current.value);
            current = current.next;
        }
        console.log(result.join(' '));
    }
}

// Logic
const ListA = new SingleLinkedList();
ListA.InsertAtBeginning (3);
ListA.InsertAtBeginning (4);
ListA.InsertAtEnd(1);
ListA.InsertAtIndex(2,2);
ListA.DeleteNodeAtIndex(3);
ListA.Traverse();