#include <stdio.h>
#include <strings.h>

void String_Concatenate (char* destination,char* origin);

int main(void)
{
    char str1[50] = "Hello";
    char str2[50] = " World";
    char str3[50] = " Ninmah";
    strcat(str1,str2);
    printf("%s\n",str1);
    String_Concatenate(str1,str3);
    printf("%s\n",str1);
    return 0;
}

void String_Concatenate (char* destination,char* origin)
{
    unsigned int dest_size = 0u;
    unsigned int orig_size = 0u;
    while('\0' != destination[dest_size])
    {
        dest_size++;
    }
    while('\0' != origin[orig_size])
    {
        destination[dest_size]=origin[orig_size];
        dest_size++;
        orig_size++;
    }
    destination[dest_size]='\0';
}