/*
    This is a program that takes 5 numbers as input from the user and prints the largest number
    Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<stdio.h>

int main()
{
    int arr[5];
    printf("Input 5 numbers:\n");
    for(int i=0;i<5;++i)
        scanf("%d",&arr[i]);
    int max=arr[0];
    int min=arr[0];
    for(int i=0;i<5;++i)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    for(int i=0;i<5;++i)
    {
        if(arr[i]<min)
         min=arr[i];
    }
    printf("%d is the largest number\n",max);
    printf("%d is the smallest number\n",min);
    return 0;
}