#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int i,num;
    int count[10]={0,0,0,0,0,0,0,0,0,0};
    char *s;
    s=malloc(1024*sizeof(char));
    scanf("%[^\n]",s);
    s=realloc(s,strlen(s)+1);
    num=strlen(s)+1;
    if(1<=num && 1000>=num)
    {
        for(i=0;i<num;i++)
        {
            if(0x30==*(s+i))
            {
                count[0]=count[0]+1;
            }else if(0x31==*(s+i))
            {
                count[1]=count[1]+1;   
            }else if(0x32==*(s+i))
            {
                count[2]=count[2]+1;
            }else if(0x33==*(s+i))
            {
                count[3]=count[3]+1;
            }else if(0x34==*(s+i))
            {
                count[4]=count[4]+1;
            }else if(0x35==*(s+i))
            {
                count[5]=count[5]+1;
            }else if(0x36==*(s+i))
            {
                count[6]=count[6]+1;
            }else if(0x37==*(s+i))
            {
                count[7]=count[7]+1;
            }else if(0x38==*(s+i))
            {
                count[8]=count[8]+1;
            }else if(0x39==*(s+i))
            {
                count[9]=count[9]+1;
            }else{/*Do nothing*/}
        }
        for(i=0;i<10;i++)
        {
            printf("%i ",count[i]);
        }
        printf("\n");
    }else{/*Do nothing*/}
    free(s);
    return 0;
}
