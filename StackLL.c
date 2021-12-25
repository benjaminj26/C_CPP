/*
    Program to implement Stack as Linked List
    Author : Benjamin Joseph
    Date : 25-12-2021
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Employee
{
    unsigned int empid;
    char *name;
    char *address;
    char *department;
    struct Employee *next;
};

void display_emp(struct Employee *top)
{
    if(top == NULL)
    {
        printf("\nStack is Empty\n\n");
    }
    else
    {
        printf("\nEmployee ID: %u\n", top->empid);
        printf("Name: %s\n", top->name);
        printf("Address: %s\n", top->address);
        printf("Department: %s\n", top->department);
        printf("\n");
    }
}

void create_emp(struct Employee **e)
{
    size_t buff_size = 10;
    *e = (struct Employee*)malloc(sizeof(struct Employee));
    (*e)->name = (char*)calloc(buff_size,sizeof(char));
    (*e)->address = (char*)calloc(buff_size,sizeof(char));
    (*e)->department = (char*)calloc(buff_size,sizeof(char));
}

void push(struct Employee **top)
{
    size_t buff_size = 10;
    struct Employee *e;
    create_emp(&e);
    printf("Enter the Employee ID of the Employee: ");
    scanf("%u", &e->empid);
    getchar();
    printf("Enter the name of the Employee: ");
    getline(&e->name,&buff_size,stdin);
    e->name[strlen(e->name)-1] = '\0';
    printf("Enter the address of the Employee: ");
    buff_size = 10;
    getline(&e->address,&buff_size,stdin);
    e->address[strlen(e->address)-1] = '\0';
    printf("Enter the department of the Employee: ");
    buff_size = 10;
    getline(&e->department,&buff_size,stdin);
    e->department[strlen(e->department)-1] = '\0';
    if (*top == NULL)
    {
        e->next = NULL;
        *top = e;
    }
    else
    {
        e->next = *top;
        *top = e;
    }
    printf("\n");
}

void delete_emp(struct Employee **top)
{
    if(*top != NULL)
    {
        struct Employee *e = (struct Employee*)malloc(sizeof(struct Employee));
        e->empid = (*top)->empid;
        e->name = (char*)malloc(strlen((*top)->name));
        strcpy(e->name, (*top)->name);
        e->address = (char*)malloc(strlen((*top)->address));
        strcpy(e->address, (*top)->address);
        e->department = (char*)malloc(strlen((*top)->department));
        strcpy(e->department, (*top)->department);
        *top = (*top)->next;
        printf("The details of the following employee are deleted\n");
        display_emp(e);
        printf("\n");
        free(e->name);
        free(e->address);
        free(e->department);
        e->next = NULL;
        free(e);
    }
    else 
    {   
        printf("\nStack is Empty\n\n");
    }
}

int main()
{
    int option;
    struct Employee *top = NULL;
    do
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Clear\n5.Exit\nEnter your choice: ");
        scanf("%d",&option);
        switch (option) 
        {
            case 1: push(&top);
            break;
            case 2: delete_emp(&top);
            break;
            case 3: display_emp(top);
            break;
            case 4: system("clear");
            break;
            case 5: exit(0);
        }
    }while(1);
}
