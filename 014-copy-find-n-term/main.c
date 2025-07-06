#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Complete the following function.

int find_nth_term(int n, int a, int b, int c) {
  //Write your code here.
    static int nterm=0,i=0;
    if(i<n)
    {
        if(0==i)
        {
            nterm=a;
        }
        else if(1==i)
        {
            nterm=b;
        }
        else if(2==i)
        {
            nterm=c;
        }
        else if(3==i)
        {
            nterm=a+b+c;
        }
        else if(4<=i)
        {
            a=b;
            b=c;
            c=nterm;
            nterm=a+b+c;
        }
        i++;
        find_nth_term(n,a,b,c);
    }else{/*Do nothing*/}
    return nterm;
}

int main() {
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    if(((1<=n)&&(20>=n))&&((1<=a)&&(100>=a))&&((1<=b)&&(100>=b))&&\
        ((1<=c)&&(100>=c)))
    {
        int ans = find_nth_term(n, a, b, c);
        printf("%d", ans);
    }else{/*Do nothing*/}
    return 0;
}
