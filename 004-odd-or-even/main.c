#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int32_t input_number=0ul;
    printf("This program check if a number is odd or even:\r\n");
    scanf("%d",&input_number);
    if(input_number%2==0ul)
    {
        printf("%d is odd\r\n",input_number);
    }
    else
    {
        printf("%d is even\r\n",input_number);
    }
    return 0;
}