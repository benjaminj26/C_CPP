/*
    Program to take command line arguments
    Author: Benjamin Joseph
    Date: 03/07/2021 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void primerange(int low, int upp)
{
    // printf("Input the lower limit: ");
    // int low;scanf("%d",&low);
    // printf("Input the upper limit: ");
    // int upp;scanf("%d",&upp);
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

void bsort(int Ar[], int n)
{
    int tmp;
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
    printf("The sorted array is:\n");
    for(int k=0;k<n;k=k+1)
        printf("%d\t",Ar[k]);
}

int main(int argc, char *argv[])
{
    char *op=argv[1];
    int n1,n2,i,j;
    if(strcmp(op,"add")==0)
    {
        n1=atoi(argv[2]);
        n2=atoi(argv[3]);
        printf("%d",n1+n2);
    }
    else if(strcmp(op,"subtract")==0)
    {
        n1=atoi(argv[2]);
        n2=atoi(argv[3]);
        printf("%d",n1-n2);
    }
    else if(strcmp(op,"multiply")==0)
    {
        n1=atoi(argv[2]);
        n2=atoi(argv[3]);
        printf("%d",n1*n2);
    }
    else if(strcmp(op,"divide")==0)
    {
        n1=atoi(argv[2]);
        n2=atoi(argv[3]);
        printf("%d",n1/n2);
    }
    else if(strcmp(op,"avg")==0)
    {
        n1=atoi(argv[2]);
        n2=atoi(argv[3]);
        printf("%d",(n1+n2)/2);
    }
    else if(strcmp(op,"primerange")==0)
    {
        n1=atoi(argv[2]);
        n2=atoi(argv[3]);
        primerange(n1,n2);
    }
    else if(strcmp(op,"bsort")==0)
    {
        int ar[argc-2];
        for(i=0,j=2;i<argc-2,j<argc;++i,++j)
            ar[i]=atoi(argv[j]);
        bsort(ar,argc-2);
    }
    else
        printf("Command Not Recognized!!\n");
    return 0;
}