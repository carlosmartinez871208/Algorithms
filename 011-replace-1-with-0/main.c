#include <stdlib.h>
#include <stdio.h>

#define BASE (10ul)
#define ZERO (0ul)
#define ONE  (1ul)

/* Algorithm: sustitute ones with zero.
** 
** 19803 the result will be 09803 or 9803
*/

static uint32_t sustitute_one_with_zeros (uint32_t input_number);

int main(void)
{
    uint32_t input_number    = 0ul;
    uint32_t changed_number = 0ul;
    scanf("%d",&input_number);
    changed_number = sustitute_one_with_zeros(input_number);
    printf("Sustitution number: %d\r\n",changed_number);
    return 0;
}

uint32_t sustitute_one_with_zeros (uint32_t input_number)
{
    uint32_t sustitution=input_number;
    uint32_t changer = 1ul;
    if (sustitution!=ONE)
    {
        while((input_number/BASE)!=0u)
        {
            if(ONE==input_number%10)
            {
                sustitution -= changer; 
            }
            changer*=BASE;
            input_number=input_number/BASE;
        }
        if(ONE==input_number%10)
        {
            sustitution -= changer; 
        }
        else{/*Do nothing*/}
    }
    else
    {
        sustitution=ZERO;
    }
    return sustitution;
} 