/*
    Program to implement Queue as an array
    Author : Benjamin Joseph
    Date : 01-12-2021
*/
#include <stdio.h>

void print_queue(int front, int rear, int arr[])
{
    for(int i=front; i<rear; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    char ch;
    int size;
    printf("Input the size of the queue: ");
    scanf("%d", &size);
    int arr[size];
    int front=0,rear=0,opt;
    do
    {
        printf("1.Enqueue\n2.Dequeue\nInput your choice: ");
        scanf("%d",&opt);
        if(opt == 1)
        {
            if(rear == size)
                printf("The queue is full\n");
            else
            {
                printf("Input the element: ");
                scanf("%d",&arr[rear++]);
                printf("The Queue after insertion is:\n");
                print_queue(front,rear,arr);
            }
        }
        else if(opt == 2)
        {
            if(front == rear)
                printf("\nQueue is empty\n");
            else
            {
                printf("\n%d is deleted\n",arr[front++]);
                printf("The Queue after deletion is:\n");
                print_queue(front,rear,arr);
                for(int i=0; i<rear; ++i)
                {
                    arr[i] = arr[i+1];
                }
                front--;
                rear--;
            }
        }
        printf("Do you want to continue?(y/n):");
        getchar();
        scanf("%c", &ch);
    }while(ch == 'y');
    return 0;
}
