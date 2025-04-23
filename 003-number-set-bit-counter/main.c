#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

static void      get_bit_count_from_input_number (int32_t input_value,u_int8_t* result); 
static int32_t   get_pow                         (int32_t input_value,u_int8_t exponent);

int main(void)
{
    int32_t   input_value     = 0u;
    u_int8_t  results[3] = {0u,0u,0u};
    printf("This program counts the number of bits of a input number: \r\nInput a value from keyboard: ");
    scanf("%d",&input_value);
    get_bit_count_from_input_number(input_value,results);
    printf(" Input value: %d, it is compounded by: %d bit(s), %d bit(s) are set, %d bit(s) are down.\r\n",input_value,results[0],results[1],results[2]);
    return 0;
}

/* Algorithm: count how many bits a number has.
** i.e. 0 -> has only one bit.
** i.e. 1 -> has only one bit.
** i.e. 2 -> has two bits.
** input_value <= 1 -> has 1 bit.
** input_value <= 3 -> has 2 bits.
** input_value <= 7 -> has 3 bits.
** input_value <=15 -> has 4 bits.
** input_value <=31 -> has 5 bits.
** 
** input_value >= (2^index). i.e. 3: index = 0, 2^0 = 1, then 3 >= 1 = yes, then increase index+1.
**                                   index = 1, 2^1 = 2, then 3 >= 2 = yes, then increase index+1.
**                                   index = 2, 2^2 = 4, then 3 >= 4 = No, escape from loop.
** index = 2.
**
** input_value >= (2^index). i.e. 4: index = 0, 2^0 = 1, then 4 >= 1 = yes, then increase index+1.
**                                   index = 1, 2^1 = 2, then 4 >= 2 = yes, then increase index+1.
**                                   index = 2, 2^2 = 4, then 4 >= 4 = yes, then increase index+1.
**                                   index = 3, 2^3 = 8, then 4 >= 8 = No, escape frum loop.
*/

void get_bit_count_from_input_number (int32_t input_value,u_int8_t* result)
{
    u_int8_t* number_of_bits=result;
    int32_t   pow_comparer = 1ul;
    if(0ul!=input_value)
    {
        for(u_int8_t index=0;input_value>=pow_comparer;++index)
        {
            pow_comparer = get_pow (2,index);
            *number_of_bits     = index;
            if((input_value & (u_int32_t)pow_comparer)!= 0){
                *(number_of_bits+1) = *(number_of_bits+1) + 1;
            }
            else{}
        }
        *(number_of_bits+2) = *(number_of_bits)-*(number_of_bits+1);
    }
    else
    {
        *number_of_bits     = 1ul;
        *(number_of_bits+1) = 0ul;
        *(number_of_bits+2) = 1ul;
    }
}

int32_t get_pow (int32_t input_value, u_int8_t exponent)
{
    int32_t pow_result=input_value;
    if(0u!=exponent)
    {
        for(uint8_t index=1u;index<exponent;index++)
        {
            pow_result *= input_value;
        }
    }
    else
    {
        pow_result = 1ul;
    }
    return pow_result;
}
