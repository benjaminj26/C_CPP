/*
    This is a program to print prime numbers in a given range
    Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<stdio.h>

int main()
{
    printf("Input the lower limit: ");
    int low;scanf("%d",&low);
    printf("Input the upper limit: ");
    int upp;scanf("%d",&upp);
    for(int i=low;i<upp;i+=1)
    {
        int flag=0;
        for(int j=2;j<(i+1)/2;j+=1)
        {
            if(i%j==0)
                flag+=1;
        }
        if(flag==0 && i!=1 && i!=4)
            printf("%d\n",i);
    }
    return 0;
}
