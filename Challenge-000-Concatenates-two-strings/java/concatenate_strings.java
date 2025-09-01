/*First program in JAVA after many years*/
/*
In JAVA a class is a template that defines the structure and behaviour of the objects.
A Class has attributes (variables): this data describes the object status.
Methods (functions): make the actions or behaviours that an object can do.
Constructors: Initialize new class objects.
*/
public class concatenate_strings
{
    public static void main(String[] args)
    {
        String str1 = "Hello";
        String str2 = " World";
        String result = str1 + str2; // result will be "Hello World"
        System.out.println(result);

        //or 
        /*String str1 = "Hello";
        String str2 = " World";
        String result = str1.concat(str2); // result will be "Hello World"
        System.out.println(result);*/

        //or
        /*StringBuilder sb = new StringBuilder();
        sb.append("Hello");
        sb.append(" World");
        String result = sb.toString(); // result will be "Hello World"
        System.out.println(result);*/

        //or
        /*String result = String.join("", "Hello", " World"); // result will be "Hello World"
        // You can also add a delimiter:
        // String resultWithDelimiter = String.join(", ", "Hello", "World"); // resultWithDelimiter will be "Hello, World" */
    }
}
