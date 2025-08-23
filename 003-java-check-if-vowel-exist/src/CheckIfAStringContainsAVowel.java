/*First program in JAVA after many years*/
/*
In JAVA a class is a template that defines the structure and behaviour of the objects.
A Class has attributes (variables): this data describes the object status.
Methods (functions): make the actions or behaviours that an object can do.
Constructors: Initialize new class objects.
*/
public class CheckIfAStringContainsAVowel
{
    public static void main(String[] args)
    {
        System.out.println("This program checks if a string has vowel!!");
        System.err.println(StringContainsVowels("TV"));
        System.err.println(StringContainsVowels("Radio"));
    }

    public static Boolean StringContainsVowels(String input)
    {
        return input.toLowerCase().matches(".*[aeiou].*");
    }
}
