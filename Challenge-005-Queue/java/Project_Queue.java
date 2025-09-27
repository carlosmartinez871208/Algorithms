/* Template for Java program */
public class Project_Queue
{
    public static void main(String[] args)
    {
        Queue queue = new Queue();
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);

        System.out.println("Frente: " + queue.peek()); // 10
        System.out.println("Dequeue: " + queue.dequeue()); // 10
        System.out.println("Nuevo frente: " + queue.peek()); // 20
    }
}
