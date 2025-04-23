#include <stdlib.h>
#include <stdio.h>

typedef enum {false=0,true}bool;

static uint8_t get_string_lenght (uint8_t* input_string);
static bool    compare_strings   (uint8_t* input_string1,uint8_t* input_string2);

int main(void)
{
    u_int8_t str_1[20];
    u_int8_t str_2[20];
    bool     str_cmp=false;
    scanf("%s",str_1);
    scanf("%s",str_2);
    str_cmp=compare_strings(str_1,str_2);
    printf("%d\r\n",str_cmp);
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

bool compare_strings   (uint8_t* input_string1,uint8_t* input_string2)
{
    bool comparation = true;
    u_int8_t str1_size = get_string_lenght(input_string1);
    u_int8_t str2_size = get_string_lenght(input_string2);
    if(str1_size == str2_size)
    {
        for(uint8_t index=0;index<str1_size;index++)
        {
            if(*(input_string1+index) != *(input_string2+index))
            {
                comparation = false;
                index = str1_size;
            }
            else{/*Do nothign*/}
        }
    }
    else
    {
        comparation = false;
    }
    return comparation; 
}