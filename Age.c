/* 
    Program to check eligibility for voting
    Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<stdio.h>

int main()
{
    int age;
    printf("Input the age of the candidate: ");
    scanf("%d",&age);
    if(age>=21)
        printf("\nCongratulations! You are eligible for casting your vote\n");
    return 0;
}
