/*First program in JAVA after many years*/
/*
In JAVA a class is a template that defines the structure and behaviour of the objects.
A Class has attributes (variables): this data describes the object status.
Methods (functions): make the actions or behaviours that an object can do.
Constructors: Initialize new class objects.
*/
public class CheckIfANumberIsPrime
{
    public static void main(String[] args)
    {
        System.out.println("This program checks if a number is prime!!");
        System.out.println(IsPrime(4));
        System.out.println(IsPrime(2));
        System.out.println(IsPrime(11));
    }

    public static Boolean IsPrime(int number)
    {
        if(0!=number && 1!=number)
        {
            for(int i=2;i<number;i++)
            {
                if(0==(number%i))
                {
                    return false;
                }
                else{/* Do nothing */}
            }
        }
        else
        {
            return false;
        }
        return true;
    }
}
