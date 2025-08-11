#include <stdio.h>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

typedef void (*functionPtr)(int,int);

void sum(int a,int b);
void sub(int a,int b);
void mul(int a,int b);
void div(int a,int b);

int main (void)
{
    functionPtr arithmeticOp [4]={sum,sub,mul,div};
    for(int i=0;i<4;i++)
    {
        arithmeticOp[i](4,2);
    }
    return EXIT_SUCCESS;
}

void sum(int a,int b)
{
    int res = a+b;
    printf("Sum (%d,%d): %d\n",a,b,res);
}

void sub(int a,int b)
{
    int res = a-b;
    printf("Subtract (%d,%d): %d\n",a,b,res);
}

void mul(int a,int b)
{
    int res = a*b;
    printf("Multiplication (%d,%d): %d\n",a,b,res);
}

void div(int a,int b)
{
    if(0!=b)
    {
        int res = a/b;
        printf("Division (%d,%d): %d\n",a,b,res);
    }
    else
    {/*Do nothing*/}
}