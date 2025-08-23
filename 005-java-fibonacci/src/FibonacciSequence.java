/*First program in JAVA after many years*/
/*
In JAVA a class is a template that defines the structure and behaviour of the objects.
A Class has attributes (variables): this data describes the object status.
Methods (functions): make the actions or behaviours that an object can do.
Constructors: Initialize new class objects.
*/
public class FibonacciSequence
{
    public static void main(String[] args)
    {
        System.out.println("Calculates Fibonacci Sequence!!");
        Fibonaci(5);
    }

    public static void Fibonaci(int number)
    {
        int a=0,b=1,fib;
        System.out.println("0");
        System.out.println("1");
        for(int i=3;i<=number;i++)
        {
            fib=a+b;
            System.out.println(fib);
            a=b;
            b=fib;
        }
    }
}
