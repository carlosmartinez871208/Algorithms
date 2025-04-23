#include <stdlib.h>
#include <stdio.h>

#define BASE (10ul)

static uint8_t get_string_lenght (uint8_t* input_string);
static void    get_array_reverse (uint8_t* input_array,uint8_t* output_array);

int main(void)
{
    u_int8_t str_1[20];
    u_int8_t str_2[20];
    scanf("%s",str_1);
    get_array_reverse(str_1,str_2);
    printf("%s\r\n",str_2);
    return 0;
}

uint8_t get_string_lenght (uint8_t* input_string)
{
    u_int8_t string_length = 0u;
    while (*(input_string+string_length)!=0u)
    {
        string_length++;
    }
    return string_length;
}

void get_array_reverse (uint8_t* input_array,uint8_t* output_array)
{
    uint8_t array_size=get_string_lenght(input_array)-1u;
    for(uint8_t index=0u;index<=array_size;index++)
    {
        *(output_array+index) = *(input_array+(array_size-index));
    }
} 