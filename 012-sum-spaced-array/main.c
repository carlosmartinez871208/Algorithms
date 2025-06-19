#include <stdio.h>
#include <stdlib.h>

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int i,n,sum=0;
    int *arr;
    scanf("%i",&n);
    if(1<=n && 1000>=n)
    {
        arr = malloc(n * sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d", arr+i);
            sum=sum+*(arr+i);
        }
        printf("%d\n",sum);
    }else{/*Do nothing*/}
    free(arr);
    return 0;
}
