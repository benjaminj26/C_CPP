/*
    Program to demonstrate the use of conditional operator
    Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<stdio.h>

int main()
{
    int a;
    printf("Input a number: ");
    scanf("%d",&a);
    char res[4];
    (a%2==0)?printf("Even"):printf("Odd");
    (a>=0)?printf("\nPositive"):printf("\nNegative");
    return 0;
}