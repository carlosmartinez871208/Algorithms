public class main_sll
{
    public static void main(String[] args){
        SingleLinkedList ListA = new SingleLinkedList();
        SingleLinkedList ListB = new SingleLinkedList();
        ListA.InsertAtBeginning(2);
        ListA.InsertAtEnd(1);
        ListA.InsertAtIndex(2, 3);
        ListA.InsertAtEnd(4);
        ListA.Traverse();
        ListB.Copy(ListA.head);
        ListB.SwapNodes(2, 4);
        ListB.IncrementalMerge(ListA.head);
        ListB.Traverse();
    }
}
