/*
    Simple program to demonstrate file input and output
    Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
    FILE *ptr;
    char tr[25];
    if(strcmp(argv[1],"write")==0)
    {
        ptr=fopen("Life skills.txt","w");
        char str1[]="Welcome to Kerala\n";
        char str2[]="Hello How are You\n";
        fprintf(ptr,"%s%s",str1,str2);
        fclose(ptr);
    }
    else if(strcmp(argv[1],"append")==0)
    {
        ptr=fopen("Life skills.txt","a");
        char str1[]="Welcome to Kerala\n";
        char str2[]="Hello How are You\n";
        fprintf(ptr,"%s%s",str1,str2);
        fclose(ptr);
    }
    else if(strcmp(argv[1],"read")==0)
    {
        ptr=fopen("Trial.txt","r");
        while(!feof(ptr))
        {
            fgets(tr,18,ptr);
            printf("%s",tr);
        }
        fclose(ptr);
    }
    return 0;
}