#include <stdlib.h>
#include <stdio.h>

#define BASE (10ul)

/* Algorithm: number reverse.
** 
** Check that 10/10 = 1 and 10%10=0. So, 15/10 = 1, 15%10=5. Therefore 1/10 = 0, 1%10=1. Loop will be skipped if divison is equal to 0.
** i.e. 15678 the output shall be 87651.
*/

static uint32_t get_number_reverse (uint32_t input_number);

int main(void)
{
    uint32_t input_number    = 0ul;
    uint32_t reversed_number = 0ul;
    scanf("%d",&input_number);
    reversed_number = get_number_reverse(input_number);
    printf("Reversed number: %d\r\n",reversed_number);
    return 0;
}

uint32_t get_number_reverse (uint32_t input_number)
{
    uint32_t reversed_number=0ul;
    while((input_number/BASE) != 0u)
    {
        reversed_number = ((input_number%BASE)+(BASE*reversed_number));
        input_number = input_number/BASE;
    }
    reversed_number = input_number+(BASE*reversed_number);
    return reversed_number;
} 