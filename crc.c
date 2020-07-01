# Cyclic-Redundancy-Check-CRC-
#include<stdio.h>
#include<string.h>
#define N strlen(g)

char t[28],cs[28],g[]="1001";
int a,e,c;

void function()
{
    for(c = 1; c<N ; c++)
    {
        cs[c] = ((cs[c] == g[c])?'0':'1');
    }
}
void crc()
{
    for(e = 0; e<N ; e++)
    {
        cs[e] = t[e];
    }
    do
    {
        if(cs[0] == '1')
        {
            function();
        }
        for(c = 0; c<N-1; c++)
        {
            cs[c] = cs[c+1];
        }
        cs[c] = t[e++];
    }while(e <= a+N-1);
}

int main()
{
    printf("\n Enter Data:");
    scanf("%s",t);
    printf("\n");
    printf("\n Generating polynomial : %s",&g);
    a = strlen(t);
    for(e = a; e<a+N-1; e++)
    {
        t[e]='0';
    }
    printf("\n Paded data is: %s\n",t);
    crc();
    printf("\n CRC is: %s",cs);
    for(e = a; e<a+N-1; e++)
    {
        t[e] = cs[e-a];
    }
    printf("\n Final Data to be sent:%s\n",t);
    printf("\n Test error detection o(yes) 1(no)?:");
    scanf("%d",&e);

    if(e == 0)
    {
        do
        {
        printf("\nEnter the position where error is to be inserted : ");
        scanf("%d",&e);
        }
        while(e==0 || e>a+N-1);

        t[e-1]=(t[e-1]=='0')?'1':'0';
        printf("\nErroneous data : %s\n",t);

    }
    crc();
    for(e=0;(e<N-1) && (cs[e]!='1');e++);
    {
        if(e<N-1)
        {
            printf("\nError detected \n\n");
        }
        else
        {
             printf("\nNo error detected\n\n");
        }
    }
    return 0;

}
