/*
    This is a program that shows the functionality of stack
    It includes the usage of functions to push and pop elements into an array
    Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
int main()
{
    int arr[10],top=0;
    char ar[10];
    do
    {
        printf("Input your choice: ");
        // printf("\n1.Push\n2.Pop\n3.Show the stack\n4.Exit\nEnter your choice: ");
        // scanf("%d",&opt);
        // switch(opt)
        // {
        //     case 1 : top=push(arr,top);
        //     break;
        //     case 2 : top=pop(arr,top);
        //     break;
        //     case 3 : display(arr,top);
        //     break;
        //     case 4 : exit(0);
        // }
        scanf("%s",ar);
        if(strcmp(ar,"push")==0)
        {    
            top=push(arr,top);
            // break;
        }
        else if(strcmp(ar,"pop")==0)
        {    
            top=pop(arr,top);
            // break;
        }
        else if(strcmp(ar,"display")==0)
        {    
            display(arr,top);
            // break;
        }
        else if(strcmp(ar,"exit")==0)
            exit(0);
    }while(1);
    return 0;
}
