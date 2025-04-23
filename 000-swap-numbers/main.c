#include <stdlib.h>
#include <stdio.h>

static void swap_method_1 (int x,int y);
static void swap_method_2 (int x,int y);
static void swap_method_3 (int* x,int* y);
static void swap_method_4 (int* x,int* y);

int main(void)
{
    int num1=2;
    int num2=7;
    int* p_num1 = &num1;
    int* p_num2 = &num2;
    printf("This program Swaps two number\r\n");
    swap_method_1(num1,num2);
    printf("After method 1: x=%d, y=%d\r\n",num1,num2);
    swap_method_2(num1,num2);
    printf("After method 2: x=%d, y=%d\r\n",num1,num2);
    swap_method_3(&num1,&num2);
    printf("After method 3: x=%d, y=%d\r\n",num1,num2);
    swap_method_4(&num1,&num2);
    printf("After method 4: x=%d, y=%d\r\n",num1,num2);
    return 0;
}

void swap_method_1 (int x,int y) /* This method make the swap locally, variables values from source function are not modified. */
{
    int z=x;
    printf("Method 1\r\n");
    printf("x=%d, y=%d\r\n",x,y);
    x=y;
    y=z;
    printf("x=%d, y=%d\r\n",x,y);
}

void swap_method_2 (int x,int y) /* This method make the swap locally, variables values from source function are not modified. */
                                 /* The difference with method 1: an extra variable is not being used.*/
{
    printf("Method 2\r\n");
    printf("x=%d, y=%d\r\n",x,y);
    x=x+y; /*x=3+7=10*/
    y=x-y; /*y=10-7=3*/
    x=x-y; /*x=10-3=7*/
    printf("x=%d, y=%d\r\n",x,y);
}

void swap_method_3 (int* x,int* y) /* This method make swap locally and also the swap occurs within source function: */
                                   /* The variables addresses are received, this function makes the swap with the address de-reference.  */
                                   /* Variables addresses are not being modified.*/
                                   /* This method uses algorithms from method 3 */
{
    printf("Method 3\r\n");
    printf("x=%d, y=%d\r\n",*x,*y);
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
    printf("x=%d, y=%d\r\n",*x,*y);
}

void swap_method_4 (int* x,int* y) /* This method make swap locally and also the swap occurs within source function: */
                                   /* The variables addresses are received, this function makes the swap of the variables addresses.  */
                                   /* The swap memory address is only performed in local scope, source function keeps original addresses. */
{
    printf("Method 4\r\n");
    printf("x=%d, y=%d\r\n",*x,*y);
    int* z=x;
    x=y;
    y=z;
    printf("x=%d, y=%d\r\n",*x,*y);
}