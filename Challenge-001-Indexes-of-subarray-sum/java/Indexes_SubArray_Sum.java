

/*First program in JAVA after many years*/
/*
In JAVA a class is a template that defines the structure and behaviour of the objects.
A Class has attributes (variables): this data describes the object status.
Methods (functions): make the actions or behaviours that an object can do.
Constructors: Initialize new class objects.
*/
public class Indexes_SubArray_Sum
{
    public static void main(String[] args)
    {
        int target = 13;
        int[] arr_input = {1,2,3,4,5,6,7,8,9,10};
        int[] output = SubArraySum(arr_input,target);
        if(-1 == output[0]){
            System.out.println("["+output[0]+"]");
            System.out.println("There is no subarray with sum "+target+".");
        }else{
            System.out.println("["+output[0]+","+output[1]+"]");
            System.out.println("The sum of elements from "+output[0]+" to "+output[1]+" is "+target+".");
        }
    }

    public static int[] SubArraySum (int[] input,int target)
    {
        int[] output = {0,0};
        int arr_size = input.length;
        int i=0,j=0,sum=0;
        while (i<arr_size&&j<arr_size){
            if(target > sum){
                sum += input[j];
                j++;
            }else if(target < sum){
                sum -= input[i];
                i++;
            }else{
                output[0] = i+1;
                output[1] = j;
                return output;
            }
        }
        output[0] = -1;
        return output;
    }
}
