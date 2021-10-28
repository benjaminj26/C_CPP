/*
    Program to print Fibonacci series in a given range
    Author : Benjamin Joseph
    Date : 09-09-2021
*/

#include<stdio.h>

int main()
{
    int lim,prev1=0,prev2=0,next=0;
    printf("Input the number of elements you want: ");
    scanf("%d",&lim);
    for(int i=0; i<lim; ++i)
    {
        if(next == 0)
        {
            printf("%d\n",next);
            next = 1;
            goto LOOP;
        }
        else
        {
            LOOP:printf("%d\n",next);
            prev1 = prev2;
            prev2 = next;
            next = prev1 + prev2;
        }
    }
    return 0;
}
