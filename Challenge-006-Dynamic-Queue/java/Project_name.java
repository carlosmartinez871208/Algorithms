/* Template for Java program */
public class Project_name
{
    public static void main(String[] args)
    {
        DynamicQueue q = new DynamicQueue(4);
        System.out.println("== Prueba de enqueue y crecimiento dinámico ==");
        for (int i = 1; i <= 10; i++) {
            q.enqueue(i);
            System.out.println("Enqueued: " + i + " -> " + q + " (size=" + q.size() + ", cap=" + q.capacity() + ")");
        }

        System.out.println("\n== Prueba de dequeue parcial ==");
        for (int i = 0; i < 5; i++) {
            int val = q.dequeue();
            System.out.println("Dequeued: " + val + " -> " + q + " (size=" + q.size() + ", cap=" + q.capacity() + ")");
        }

        System.out.println("\nPeek actual: " + q.peek());

        System.out.println("\n== Enqueue tras dequeues (comprobando uso circular) ==");
        for (int i = 11; i <= 14; i++) {
            q.enqueue(i);
            System.out.println("Enqueued: " + i + " -> " + q + " (size=" + q.size() + ", cap=" + q.capacity() + ")");
        }

        System.out.println("\n== Vaciando cola ==");
        while (!q.isEmpty()) {
            System.out.println("Dequeued: " + q.dequeue() + " -> " + q);
        }

        System.out.println("Dequeue en cola vacía: " + q.dequeue());
        System.out.println("Peek en cola vacía: " + q.peek());

        System.out.println("\n== Reutilización tras clear ==");
        q.enqueue(42);
        q.enqueue(43);
        System.out.println(q);
        q.clear();
        System.out.println("Después de clear: " + q + " (size=" + q.size() + ")");
        q.enqueue(99);
        System.out.println("Tras nuevo enqueue: " + q);
    }
}
