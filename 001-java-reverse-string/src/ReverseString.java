/*First program in JAVA after many years*/
/*
In JAVA a class is a template that defines the structure and behaviour of the objects.
A Class has attributes (variables): this data describes the object status.
Methods (functions): make the actions or behaviours that an object can do.
Constructors: Initialize new class objects.
*/
public class ReverseString
{
    public static void main(String[] args)
    {
        String inputStr = "ABDEFGHIJKLMNOPQRSTUVWXYZ";
        System.out.println("This exercise reverse an string!");
        System.out.println(inputStr);
        System.out.println(Reverse(inputStr));
    }

    public static String Reverse (String input)
    {
        if(null == input)
        {
            throw new IllegalArgumentException("Null is not a valid input");
        }
        else
        {
            StringBuilder output = new StringBuilder();
            char[] chars = input.toCharArray();
            for (int i=(chars.length-1);i>=0;i--)
            {
                output.append(chars[i]);
            }
            return output.toString();
        }
    }
}
