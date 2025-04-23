#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int32_t input_number=0ul;
    uint8_t flag=0u;
    printf("This program check if a number is prime:\r\n");
    scanf("%d",&input_number);
    if(0!=input_number && 1!=input_number)
    {
        for(u_int32_t index=2;index<input_number;index++)
        {
            if(input_number%index==0)
            {
                flag=1ul;
                index=input_number;
            }
        }
        if(1u==flag)
        {
            printf("%d is not a prime number\r\n",input_number);
        }
        else
        {
            printf("%d is a prime number\r\n",input_number);
        }
    }
    else
    {
        printf("%d is not a prime number\r\n",input_number);
    }
    return 0;
}