/*
    Simple program to demonstrate file input and output
    Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<stdio.h>
#include<string.h>

struct College
{
    char name[20];
    int rno;
    char branch[50];
    int yob;
};

int main(int argc, char *argv[])
{
    char tr[25];
    FILE *ptr;
    if(strcmp(argv[1],"write")==0)
    {
        ptr=fopen("Trial.txt","w");
        char str1[]="Welcome to Ooty\n";
        char str2[]="Nice to meet you\n";
        fprintf(ptr,"%s%s",str1,str2);
        fclose(ptr);
    }
    else if(strcmp(argv[1],"append")==0)
    {
        ptr=fopen("Trial.txt","a");
        char str1[]="Welcome to Ooty\n";
        char str2[]="Nice to meet you\n";
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
    else if(strcmp(argv[1],"write-struct")==0)
    {
        struct College c;
        strcpy(c.name,"Bryce Loski");
        c.rno=19;
        strcpy(c.branch,"Business Administration");
        c.yob=1987;
        ptr=fopen("Trial.bin","wb");
        fwrite(&c,sizeof(c),1,ptr);
        fclose(ptr);
    }
    else if(strcmp(argv[1],"read-struct")==0)
    {
        struct College d;
        ptr=fopen("Trial.bin","rb");
        fread(&d,sizeof(d),1,ptr);
        printf("Name: %s\n",d.name);
        printf("Roll Number: %d\n",d.rno);
        printf("Branch: %s\n",d.branch);
        printf("Year of Birth: %d\n",d.yob);
        fclose(ptr);
    }
    return 0;
}
