/*
    This is a program to calculate the simple interest by taking principal amount, rate and time as the input from the user
    Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<stdio.h>

int main()
{
    int p,r,t;
    printf("Enter the Principal Amount: ");
    scanf("%d",&p);
    printf("\nEnter the rate: ");
    scanf("%d",&r);
    printf("\nEnter the time: ");
    scanf("%d",&t);
    int SI=(p*r*t)/100;
    printf("\nThe simple interest is: %d",SI);
    return 0;
}