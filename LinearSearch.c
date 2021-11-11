/*
    This is a program to search for an element in an array by taking input from the user and return the position of the element
    Author: Benjamin Joseph
    Date: 05/07/2021
*/
#include<stdio.h>

int main()
{
    printf("Input the number of elements: ");
    int num,flag=0;
    scanf("%d",&num);
    printf("Input %d elements:\n", num);
    int Ar[num];
    for(int i=0;i<num;++i)
    {
        scanf("%d",&Ar[i]);
    }
    for(int i=0;i<num;++i)
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
