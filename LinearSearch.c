/*
    This is a program to search for an element in an array by taking input from the user and return the position of the element
    Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<stdio.h>

int main()
{
    int Ar[10]={90,70,50,20,10,40,100,60,30,80};
    printf("Enter the integer to be searched(10-100): ");
    int n,flag=0;
    scanf("%d",&n);
    for(int i=0;i<10;i=i+1)
    {
        if(Ar[i]==n)
        { 
         printf("The position of the integer is: %d",i);
         flag=flag+1;
         break;
        }
    }
    if(flag==0)
     printf("\nInvalid Input");
    return 0;
}