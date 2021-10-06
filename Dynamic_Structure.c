/*
    Program to store the details of employees in a dynamically allocated structure
    Author : Benjamin Joseph
    Date : 04-10-2021
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declaring structure emp
struct emp
{
    int empid;
    char name[20];
    char surname[50];
    char address[50];
    char phone_num[12];
    char job[50];
};

//Function for reading the details of the employeess
void emp_input(size_t size, struct emp *employee)
{
    //Reading the employee id of the employee
    INPUT:printf("Input the employee id: ");
    int id,flag=0;
    scanf("%d",&id);
    for(int i=0; i<size; ++i)
    {
        if(id == employee[i].empid)
        {
            flag+=1;
        }
    }
    if(flag == 0)
        employee[size].empid = id;
    else
    {
        printf("\nEmployee ID already used!!!\n\n");
        goto INPUT;
    }
    getchar();

    //Reading the name of the employee
    printf("Input the name of the employee: ");
    fgets(employee[size].name,20,stdin);
    employee[size].name[strlen(employee[size].name)-1]='\0';

    //Reading the surname of the emoloyee
    printf("Input the surname of the employee: ");
    fgets(employee[size].surname,50,stdin);
    employee[size].surname[strlen(employee[size].surname)-1]='\0';

    //Reading the address of the emoloyee
    printf("Input the address of the employee: ");
    fgets(employee[size].address,50,stdin);
    employee[size].address[strlen(employee[size].address)-1]='\0';

    //Reading the phone number of the emoloyee
    printf("Input the phone number of the employee: ");
    fgets(employee[size].phone_num,12,stdin);
    employee[size].phone_num[strlen(employee[size].phone_num)-1]='\0';

    //Reading the job of the emoloyee
    printf("Input the job of the employee: ");
    fgets(employee[size].job,50,stdin);
    employee[size].job[strlen(employee[size].job)-1]='\0';
}

//Function for displaying the details of the employees
void emp_display(size_t size, struct emp *employee)
{
    if(size == 0)
        printf("\nThe employee list is empty\n");
    else
    {
        for(int i=0; i<size; ++i)
        {
            printf("\n<<Details of Employee%d>>\n\n",i+1);
            //Printing ID of the Employee
            printf("Employee ID: %d\n",employee[i].empid);
            //Printing Name of the Employee
            printf("Name : ");puts(employee[i].name);
            //Printing Surname of the Employee
            printf("Surname: ");puts(employee[i].surname);
            //Printing Address of the Employee
            printf("Address: ");puts(employee[i].address);
            //Printing Phone Number of the Employee
            printf("Phone Number: ");puts(employee[i].phone_num);
            //Printing Job of the Employee
            printf("Job: ");puts(employee[i].job);
        }
        printf("\n");
    }
    
}

//Function for deleting the details of the employee
void emp_delete(size_t index, size_t size, struct emp *employee)
{
    if(index < size)
    {
        for(int i=index; i<size-1; ++i)
        {
            /*Copying the details of the employee in front of the employee
            to be deleted to the address of the employee to be deleted*/
            employee[i].empid = employee[i+1].empid;
            strcpy(employee[i].name, employee[i+1].name);
            strcpy(employee[i].surname, employee[i+1].surname);
            strcpy(employee[i].address, employee[i+1].address);
            strcpy(employee[i].phone_num, employee[i+1].phone_num);
            strcpy(employee[i].job, employee[i+1].job); 
        }
    }
    printf("\nDeleted Successfully!!!\n");
}

int main()
{
    size_t size=0;
    int option;
    struct emp *employees = (struct emp*)malloc(size*sizeof(struct emp));
    do
    {
        printf("\n1.Input the details of a new employee\n2.Display the details of all the employees\n3.Delete all the details of an employee\n4.Edit the details of an employee\n5.Exit\nInput your choice: ");
        scanf("%d",&option);
        
        //Reading the details of a new employee
        if(option == 1)
        {
            size+=1;
            employees = (struct emp*)realloc(employees,(size)*sizeof(struct emp));
            emp_input(size-1,employees);
        }

        //Printing the details of all the employees
        else if(option == 2)
        {
            emp_display(size,employees);
        }

        //Deleting all the details of an employee
        else if(option == 3)
        {
            size_t id,i,flag=0;
            printf("Input the employee id of the employee: ");
            scanf("%d",&id);
            for(i=0;i<size;++i)
            {
                if(employees[i].empid == id)
                {
                    flag=1;
                    break;
                }    
                else
                    continue;
            }
            if(flag == 0)
                printf("\nINVALID USER ID!!!\n");
            else 
            {
                emp_delete(i,size,employees);
                size-=1;
                employees = (struct emp*)realloc(employees,(size)*sizeof(struct emp));

            }
        }
        //Editing the details of an employee
        else if(option == 4)
        {
            int id,i,flag=0;
            printf("Enter the employee id of the employee you want to edit: ");
            scanf("%d",&id);
            for(i=0;i<size;++i)
            {
                if(employees[i].empid == id)
                {
                    flag=1;
                    break;
                }    
                else
                    continue;
            }
            if(flag == 0)
                printf("\nINVALID USER ID!!!\n");
            else
            {
                int edit_choice;
                char ch;
                do
                {
                    printf("\n1.Name\n2.Surname\n3.Address\n4.Phone Number\n5.Job\nInput the detail you want to edit: ");
                    scanf("%d",&edit_choice);
                    getchar();
                    if(edit_choice == 1)
                    {
                        printf("Input the new name: ");
                        fgets(employees[i].name,20,stdin);
                        employees[i].name[strlen(employees[i].name)-1]='\0';
                    }
                    else if(edit_choice == 2)
                    {
                        printf("Input the new surname: ");
                        fgets(employees[i].surname,50,stdin);
                        employees[i].surname[strlen(employees[i].surname)-1]='\0';
                    }
                    else if(edit_choice == 3)
                    {
                        printf("Input the new address: ");
                        fgets(employees[i].address,50,stdin);
                        employees[i].address[strlen(employees[i].address)-1]='\0';
                    }
                    else if(edit_choice == 4)
                    {
                        printf("Input the new phone number: ");
                        fgets(employees[i].phone_num,12,stdin);
                        employees[i].phone_num[strlen(employees[i].phone_num)-1]='\0';
                    }
                    else if(edit_choice == 5)
                    {
                        printf("Input the new job: ");
                        fgets(employees[i].job,50,stdin);
                        employees[i].job[strlen(employees[i].job)-1]='\0';
                    }
                    printf("Do you want to continue?(y/n): ");
                    ch=getchar();
                }while(ch == 'y');
            }
        }
        else if(option == 5)
            exit(0);
        else
            exit(0);
    }while(1);
    free(employees);
    return 0;
}
