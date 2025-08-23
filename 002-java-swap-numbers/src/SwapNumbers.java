/*First program in JAVA after many years*/
/*
In JAVA a class is a template that defines the structure and behaviour of the objects.
A Class has attributes (variables): this data describes the object status.
Methods (functions): make the actions or behaviours that an object can do.
Constructors: Initialize new class objects.
*/
public class SwapNumbers
{
    public static void main(String[] args)
    {
        int x=8,y=5;
        System.out.println("This program swap numbers!!");
        System.err.println("x = "+x+", y = "+y);
        x=x+y;
        y=x-y;
        x=x-y;
        System.err.println("x = "+x+", y = "+y);
    }
}
