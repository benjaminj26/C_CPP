/*
    This is a program to create a minimal text editor
    Author: Benjamin Joseph
    Date: 03/07/2021
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


int main()
{
    char *ptr=NULL,ch;
    size_t buffsize=0;
    ptr=(char *)malloc(1*sizeof(char));
    printf("Input a string:\n");
    while(1)
    {
        ch=getchar();
        if((int)ch==27)
            break;
        else
        {
            ptr=realloc(ptr,(1+buffsize)*sizeof(char));
            ptr[buffsize]=ch;
            buffsize++;
        }
    }
    printf("\nThe string you entered is:\n");
    for(int i=0;i<strlen(ptr);++i)
        printf("%c",ptr[i]);
    printf("\n");
    printf("\nThe number of characters that you input is %d\n",buffsize+1);
    free(ptr);
    return(0);
}

