#include <stdio.h>
#include <stdlib.h>

int* Indexes_SubarraySum (unsigned int* input,unsigned int target);
unsigned int Array_length (unsigned int* array);

int main(void)
{
    unsigned int arr_input[] = {1,2,3,4,5,6,7,8,9,10};
    unsigned int target = 13u;
    int* arr_output = Indexes_SubarraySum(arr_input,target);
    if(-1 == arr_output[0])
    {
        printf("[%i]\n",arr_output[0]);
        printf("There is no subarray with sum %i.\n",target);
    }
    else
    {
        printf("[%i,%i]\n",arr_output[0],arr_output[1]);
        printf("The sum of elements from %i to %i position is %i.\n",arr_output[0],arr_output[1],target);
    }
    free(arr_output);
    return 0;
}

int* Indexes_SubarraySum (unsigned int* input,unsigned int target)
{
    int* output = malloc(2*sizeof(int));
    unsigned int sum=0u,i=0u,j=0u;
    unsigned int input_size = Array_length(input);
    while(i<input_size&&j<input_size)
    {
        if(target > sum)
        {
            sum += *(input+j);
            j++;
        }
        else if(target < sum)
        {
            sum -= *(input+i);
            i++;
        }
        else
        {
            *output = i+1;
            *(output+1) = j;
            return output;
        }
    }
    output=realloc(output,sizeof(int));
    output[0]=-1;
    return output;
}

unsigned int Array_length (unsigned int* array)
{
    unsigned int arr_len = 0u;
    while('\0'!=*(array+arr_len))
    {
        arr_len++;
    }
    return (arr_len-1u);
}