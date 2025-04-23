#include <stdlib.h>
#include <stdio.h>

#define BASE (10ul)
#define ZERO (0ul)

/* Algorithm: sustitute zeros with ones.
** 
** 19803 the result will be 19813
**
** 19803/10 = 1980, 19803%10 = 3.
** 1980/10  = 198,  1980%10 = 0.
** if residuos is equal to 0, there is a zero in that position.
*/

static uint32_t sustitute_zeros_with_ones (uint32_t input_number);

int main(void)
{
    uint32_t input_number    = 0ul;
    uint32_t changed_number = 0ul;
    scanf("%d",&input_number);
    changed_number = sustitute_zeros_with_ones(input_number);
    printf("Sustitution: %d\r\n",changed_number);
    return 0;
}

uint32_t sustitute_zeros_with_ones (uint32_t input_number)
{
    uint32_t sustitution=input_number;
    uint32_t changer = 1ul;
    if (sustitution!=ZERO)
        while((input_number/BASE)!=0u)
        {
            if(ZERO==input_number%10)
            {
                sustitution += changer; 
            }
            changer*=BASE;
            input_number=input_number/BASE;
        }
    else
    {
        sustitution=changer;
    }
    return sustitution;
} 