/*
	This is a program to take input fromm the user and form a matrix
	Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<stdio.h>

int main()
{
	int i,j,array[3][3],n;
	printf("Input 9 elements:\n");
	for(i=0;i<3;i=i+1)
	{
		for(j=0;j<3;j=j+1)
		{
			if(j==0)
				printf("\n");
			scanf("%d",&n);
			array[i][j]=n;
		}
	}
	printf("\nThe matrix you have entered is:\n");
	for(i=0;i<3;i=i+1)
	{
		for(j=0;j<3;j=j+1)
		{
			if(j==0)
				printf("\n");
			printf("%d\t",array[i][j]);
		}
	}
	return 0;
}