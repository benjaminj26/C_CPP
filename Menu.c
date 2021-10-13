/*
    This is a program that combines several programs as functions into a single program and uses a menu to execute the different programs
    Author: Benjamin Joseph
    Date: 10/07/2021
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void bsort();
void grades();
void lsearch();
void password();
void prime();
void si();
void array2d();
void Primerange();
void display(int array[10], int top);
int push(int array[10], int top);
int pop(int array[10],int top);

int main()
{
    int array[10],top=0;
	do
	{
		printf("\n1.Bubblesort\n2.Grades\n3Linear Search\n4.Password\n5.Prime Number Check\n6.Simple Interest\n7.2D Array\n8.Prime Range\n9.Push Stack\n10.Pop Stack\n11.Display Stack\n12.Exit\n\nEnter your choice: ");
		int n;
		scanf("%d",&n);
		switch(n)
		{
			case 1: bsort();
			break;
			case 2: grades();
			break;
			case 3: lsearch();
			break;
			case 4: password();
			break;
			case 5: prime();
			break;
			case 6: si();
			break;
			case 7: array2d();
			break;
            case 8: Primerange();
            break;
            case 9: top=push(array,top);
            break; 
			case 10: top=pop(array,top);
            break;
            case 11: display(array,top);
            break;
            case 12: exit(0);
		}
    }while(1);
	return 0;
}
void bsort()
{
	int tmp,num,n;
    printf("Input the number of elements: ");
    scanf("%d",&n);
    int Ar[n];
    printf("Input %d numbers:\n",n);
    for(int m=0;m<n;m=m+1)
    {
        scanf("%d",&num);
        Ar[m]=num;
    }
    for(int i=1;i<n;i=i+1)
    {
        for(int j=0;j<n-i;j=j+1)
        {
            if(Ar[j]>Ar[j+1])
            {
                tmp=Ar[j];
                Ar[j]=Ar[j+1];
                Ar[j+1]=tmp;
            }
        }
    }
    for(int k=0;k<n;k=k+1)
        printf("%d\t",Ar[k]);
}
void grades()
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
}
void lsearch()
{
	int Ar[5]={87,76,99,56,20};
    printf("Enter the integer to be searched: ");
    int n,flag=0;
    scanf("%d",&n);
    for(int i=0;i<5;i=i+1)
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
}
void password()
{
	int pss[15],c,i=0;
    printf("Enter the password:\n");
    while(1)
    {
        c=getch();
        if(c==13)
         break;
        else if(c==8)
        {
         i=i-2;
         printf("\b");
        }
        else
         pss[i]=c;
         printf("*");
         i=i+1;
    }
    printf("\nThe password you have entered is:\n");
    for(int j=0;j<i;j=j+1)
    {
        printf("%c",pss[j]);
    }
}
void prime()
{
	printf("Enter a number: ");
    int n,flag=0,ch;
    scanf("%d",&n);
    for(int i=2;i<(n+1)/2;i=i+1)
    {
        if(n%i==0)
         flag=flag+1;
    }
    if(flag==0 && n!=4)
     printf("%d is prime\n",n);
    else
     printf("%d is not prime\n",n);
}
void si()
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
}
void array2d()
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
}

void display(int array[10],int top)
{
    if(top==0)
        printf("\nStack is Empty!!\n");
    else
    {
        for(int i=0;i<top;++i)
        {
            printf("%d\t",array[i]);
            if(i==top-1)
                printf("\n\n\n");
        }
    }
}

int push(int array[10], int top)
{
    //int top= *k;
    if(top==9)
        printf("\nStack Overflow!!\n");
    else
    {
        printf("Input a number: ");
        int n;scanf("%d",&n);
        array[top]=n;
        top++;
        //*k++;
        printf("\n\n\n");
        display(array,top);
    }
    return top;
}

int pop(int array[10], int top)
{
    //int top= *k;
    if(top==0)
        printf("\nStack Underflow!!\n");
    else
    {
        printf("%d is deleted",array[top-1]);
        array[top]='\0';
        top--;
         //*k--;
        printf("\n\n\n");
        display(array,top);
    }
    return top;
}

// void stack()
// {
//     int arr[10],opt,top=0;
//     char ch;
//     do
//     {
//         printf("\n1.Push\n2.Pop\n3.Show the stack\n\nEnter your choice: ");
//         scanf("%d",&opt);
//         switch(opt)
//         {
//             case 1 : top=push(arr,top);
//             break;
//             case 2 : top=pop(arr,top);
//             break;
//             case 3 : display(arr,top);
//             break;
//         }
//         printf("\nDo you want to coninue?(y/n):");
//         scanf("%c",&ch);
//     }while(ch=='y');
// }
void Primerange()
{
    printf("Input the lower limit: ");
    int low;scanf("%d",&low);
    printf("Input the upper limit: ");
    int upp;scanf("%d",&upp);
    for(int i=low;i<upp;i+=1)
    {
        int flag=0;
        for(int j=2;j<(i+1)/2;j+=1)
        {
            if(i%j==0)
                flag+=1;
        }
        if(flag==0 && i!=1 && i!=4)
            printf("%d\n",i);
    }
}