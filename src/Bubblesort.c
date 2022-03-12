/*
    This is a program to accept an unsorted array as input from the user and then sort it using the Bubblesort algorithm
    Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<stdio.h>

int main()
{
    int tmp,num,n;
    printf("Input the number of elements: ");
    scanf("%d",&n);
    int Ar[n];
    printf("Input %d numbers:\n",n);
    for(int m=0;m<n;m=m+1)
    {
        scanf("%d",&num);
        Ar[m]=num;
    }
    for(int i=1;i<n;i=i+1)
    {
        for(int j=0;j<n-i;j=j+1)
        {
            if(Ar[j]>Ar[j+1])
            {
                tmp=Ar[j];
                Ar[j]=Ar[j+1];
                Ar[j+1]=tmp;
            }
        }
    }
    printf("The sorted array is:\n");
    for(int k=0;k<n;k=k+1)
        printf("%d\t",Ar[k]);
    printf("\n");
    return 0;
}
