/*
    Program to check whether a person made a profit
    Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<stdio.h>

int main()
{
    int cp,sp;//Cost price & Selling price
    printf("Input the cost price: ");
    scanf("%d",&cp);
    printf("\nInput the selling price: ");
    scanf("%d",&sp);
    if(sp>cp)
        printf("\nYou made a profit of %d\n",sp-cp);
    else if(sp<cp)
        printf("\nYou made a loss of %d\n",cp-sp);
    return 0;

}