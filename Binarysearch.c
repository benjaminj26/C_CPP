/*
    Program to impelement Binary Search 
    Author : Benjamin Joseph
    Date : 04-10-2021
*/

#include<stdio.h>


//Function for sorting the array
void Bubblesort(int size, int array[size])
{
    int tmp;
    for(int i=1;i<size;i++)
    {
        for(int j=0;j<size-i;j++)
        {
            if(array[j]>array[j+1])
            {
                tmp=array[j];
                array[j]=array[j+1];
                array[j+1]=tmp;
            }
        }
    }
}

int main()
{
    //Declaring some of the required variables
    int i,size;
        printf("Input the number of elements: ");
    scanf("%d",&size);

    //Declaring the array of the required size
    int arr[size];

    //Reading the elements of the array
    printf("Input %d elements:\n",size);   
    for(i=0;i<size;++i)
    {
        scanf("%d",&arr[i]);
    }
    
    //Sorting the array using bubblesort algorithm
    Bubblesort(size,arr);
    
    //Printing the sorted array
    printf("The sorted array is:\n");
    for(i=0;i<size;++i)
        printf("%d ",arr[i]);
    printf("\n");
    
    //Reading the number to be searched
    printf("Input the number to be searched: ");
    int num;scanf("%d",&num);
    i=size/2;
    
    //Seach for the number in the sorted array using Binary Search algorithm
    while(i>=0 && i<size)
    {
        if(num == arr[i])
            break;
        else if(num>arr[i])
            i+=i/2;
        else if(num<arr[i])
            i-=i/2;
    }
    
    //Printing the position of the element
    printf("The number %d is found at position %d\n",num,i);
    return 0;
}