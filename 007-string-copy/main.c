#include <stdlib.h>
#include <stdio.h>

typedef enum {false=0,true}bool;

static void    string_copy   (uint8_t* input_string1,uint8_t* input_string2);

int main(void)
{
    u_int8_t str_1[20];
    u_int8_t str_2[20];
    scanf("%s",str_1);
    string_copy(str_1,str_2);
    printf("%s\r\n",str_2);
    return 0;
}

void string_copy   (uint8_t* input_string1,uint8_t* input_string2)
{
    u_int8_t index=0;
    while (*(input_string1+index)!=0u)
    {
        *(input_string2+index) = *(input_string1+index);
        index++;
    }
}