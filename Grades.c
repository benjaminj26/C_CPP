/*
    This is a program that takes the marks of 3 subjects as input from the user and prints the grade based on the average of the marks entered
    Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<stdio.h>

int main()
{
    int p,c,m;
    printf("Enter the marks of Physics: ");
    scanf("%d",&p);
    printf("\nEnter the marks of Chemistry: ");
    scanf("%d",&c);
    printf("\nEnter the marks of Maths: ");
    scanf("%d",&m);
    int avg=(p+c+m)/3;
    if(avg>80 && avg<100)
     printf("A Grade");
    if(avg>60 && avg<80)
     printf("B Grade");
    if(avg>40 && avg<60)
     printf("C Grade");
    if(avg<40)
     printf("F Grade");
    if(avg<0 || avg>100)
     printf("\nInvalid Input");
    return 0;
}