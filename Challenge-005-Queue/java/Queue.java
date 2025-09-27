public class Queue{
    private static final int MAX_SIZE = 100;
    private int[] items = new int[MAX_SIZE];
    private int front = 0;
    private int rear = -1;

    public boolean isEmpty() {
        return rear < front;
    }

    public boolean isFull() {
        return rear - front + 1 == MAX_SIZE;
    }

    public void enqueue(int value) {
        if (isFull()) {
            System.out.println("Queue overflow");
            return;
        }
        items[++rear] = value;
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue underflow");
            return -1;
        }
        return items[front++];
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return -1;
        }
        return items[front];
    }
}
