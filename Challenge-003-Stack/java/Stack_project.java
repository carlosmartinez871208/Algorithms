/* Template for Java program */
public class Stack_project
{
    public static void main(String[] args)
    {
        Stack s = new Stack();
        s.push(10);
        s.push(20);
        s.push(30);

        System.out.println("Cima: " + s.peek()); // 30
        s.pop();
        System.out.println("Nueva cima: " + s.peek()); // 20
    }
}
