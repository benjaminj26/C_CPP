/*
    This is a program that uses getpass() to accept a password from the user
    Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<stdio.h>
#include <unistd.h>

int main()
{
    char *password = getpass("Enter your Password: ");
    printf("\nThe password you have entered is:\n");
    printf("%s\n",password);
    return 0;
}
