/* 
    Program to check eligibility for admission
    Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<stdio.h>

int main()
{
    int mat,phy,chem;
    printf("Input the marks of Maths:");
    scanf("%d",&mat);
    printf("\nInput the marks of Physics:");
    scanf("%d",&phy);
    printf("\nInput the marks of Chemistry:");
    scanf("%d",&chem);
    int tot=mat+phy+chem;
    int mp=mat+phy;
    if(mat>=65 && phy>=55 && chem>=50) 
    {
        if(tot>=190 || mp>=140)
            printf("\nYou are eligible for admission!!\n");
    }
    else
            printf("\nYou are not eligible for admission\n");
    return 0;
}