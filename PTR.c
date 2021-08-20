/*
    This is a program to test the functionality of pointers
    Author: Benjamin Joseph
    Date: 08-07-2021
*/
#include<stdio.h>

int main()
{
    char *ptr=NULL;
    char ch[10];
    printf("Input a String: ");
    scanf("%s",ch);
    ptr=ch;
    printf("%s\n",ptr);
    return 0;
}