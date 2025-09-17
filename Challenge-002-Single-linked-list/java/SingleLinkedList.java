public class SingleLinkedList{
    Node head;

    public SingleLinkedList(){this.head=null;}

    public void InsertAtBeginning(int data){
        Node temp = new Node(data);
        temp.next = head;
        head = temp;
    }

    public void InsertAtEnd(int data){
        Node temp = new Node(data);
        Node aux  = head;
        if(null!=aux){
            while (null!=aux.next) {
                aux = aux.next;
            }
            aux.next = temp;
        }else{
            head = temp;
        }

    }

    public void InsertAtIndex(int index,int data){
        Node temp = new Node(data);
        Node aux  = head;
        int counter = 2;
        if(null!=aux){
            if(0==index || 1==index){
                aux.next = head;
                head = temp;
            }else{
                while (counter<index && null!=aux.next) { 
                    counter+=1;
                    aux=aux.next;
                }
                temp.next = aux.next;
                aux.next = temp;
            }
        }
    }

    public void DeleteNodeAtIndex (int index){
        Node temp = head;
        Node aux;
        int counter = 2;
        if(null!=temp){
            if(0==index || 1==index){
                head = head.next;
            }else{
                while (counter<index && null!=temp.next) { 
                    counter+=1;
                    temp=temp.next;
                }
                aux = temp.next;
                temp.next = aux.next;
            }
        }
    }

    public void SwapNodes (int index1,int index2){
        Node temp1 = head;
        Node temp2 = head;
        Node aux;
        int counter = 2;
        if(null!=head){
            if(index1>index2){
                index2=index1+index2;
                index1=index2-index1;
                index2=index2-index1;
            }
            if(0==index1 || 1==index1){
                while(null!=temp1.next && index2!=counter){
                    counter += 1;
                    temp1 = temp1.next;
                }
                aux = head;
                head = temp1.next;
                temp1.next = aux;
                temp1 = temp1.next;
                aux = head.next;
                head.next = temp1.next;
                temp1.next = aux;
            }else if(index1!=index2){
                while(null!=temp1.next && index1!=counter){
                    counter += 1;
                    temp1 = temp1.next;
                }
                counter = 2;
                while(null!=temp2.next && index2!=counter){
                    counter += 1;
                    temp2 = temp2.next;
                }
                aux = temp1.next;
                temp1.next = temp2.next;
                temp2.next = aux;
                temp1 = temp1.next;
                temp2 = temp2.next;
                aux = temp1.next;
                temp1.next = temp2.next;
                temp2.next = aux;
            }
        }
    }

    public void DecrementalSort (){
        Node temp;
        Node aux = null;
        int list_size   = Size()-1;
        if(null != head){
            for(int i=0;i<list_size;i++){
                for(int j=0;j<list_size-i;j++){
                    if(0==j){
                        temp=head;
                        aux=temp.next;
                        if(temp.data < aux.data){
                            temp.next=aux.next;
                            aux.next=temp;
                            head = aux;
                        }else{
                            aux=head;
                        }
                    }else if(j>0){
                        temp=aux;
                        aux=temp.next;
                        if(temp.next.data < aux.next.data){
                            temp.next=aux.next;
                            temp=aux;
                            aux=temp.next;
                            temp.next=aux.next;
                            aux.next = temp;
                        }
                    }
                }
            }
        }
    }

    public void IncrementalSort (){
        Node temp;
        Node aux = null;
        int list_size   = Size()-1;
        if(null != head){
            for(int i=0;i<list_size;i++){
                for(int j=0;j<list_size-i;j++){
                    if(0==j){
                        temp=head;
                        aux=temp.next;
                        if(temp.data > aux.data){
                            temp.next=aux.next;
                            aux.next=temp;
                            head = aux;
                        }else{
                            aux=head;
                        }
                    }else if(j>0){
                        temp=aux;
                        aux=temp.next;
                        if(temp.next.data > aux.next.data){
                            temp.next=aux.next;
                            temp=aux;
                            aux=temp.next;
                            temp.next=aux.next;
                            aux.next = temp;
                        }
                    }
                }
            }
        }
    }

    public void Concatenate(Node list)
    {
        Node temp = list;
        if(null!=list){
            if(null!=head){
                while(null!=temp){
                    InsertAtEnd(temp.data);
                    temp = temp.next;
                }
            }
        }
    }

    public void DecrementalMerge (Node list){
        Concatenate(list);
        DecrementalSort();
    }

    public void IncrementalMerge (Node list){
        Concatenate(list);
        IncrementalSort();
    }

    public void Traverse(){
        Node temp = head;
        while (null!=temp){ 
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println();
    }

    public void Copy (Node list)
    {
        Node temp = list;
        if(null == head){
            if(null != list){
                while(null!= temp){
                    InsertAtEnd(temp.data);
                    temp = temp.next;
                }
            }
        }
    }

    public int Size (){
        Node temp = head;
        int counter = 0;
        while (null!=temp) { 
            temp = temp.next;
            counter+=1;
        }
        return counter;
    }
}