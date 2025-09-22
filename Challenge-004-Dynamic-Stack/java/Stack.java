public class Stack {
    private static final int MAX_SIZE = 100;
    private int[] items = new int[MAX_SIZE];
    private int top = -1;

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top == MAX_SIZE - 1;
    }

    public void push(int value) {
        if (isFull()) {
            System.out.println("Stack overflow");
            return;
        }
        items[++top] = value;
    }

    public void pop() {
        if (isEmpty()) {
            System.out.println("Stack underflow");
            return;
        }
        top--;
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        }
        return items[top];
    }
}