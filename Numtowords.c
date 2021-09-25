/*
    This is a program that takes a number as input and prints it in words
    Author: Benjamin Joseph
    Date: 01/08/2021
*/

#include<stdio.h>
#include<string.h>

void check(int *num, int *count, int *z_count, int *ten_count)
{
    char *ones[] = {"\b","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    char *tens[] = {"\b","\b","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    char *teens[] = {"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Ninteteen"};
    if(*count==9)
    {
        if(num!=0 && *z_count==0)
            printf("%s Hundred ",ones[*num]);
    }
    else if(*count==8)
    {
        if(*num==1)
        {
            *ten_count=1;
        }
        else
        {
            *ten_count=0;
            printf("%s ",tens[*num]);
        } 
    }
    else if(*count==7)
    {
        if(num!=0 && *z_count<3)
        {
            if(*ten_count==0)
            {
                printf("%s Million ",ones[*num]);
            }
            else
                printf("%s Million ",teens[*num]);
        }
    }
    else if(*count==6)
    {
        if(num!=0 && *z_count==0)
            printf("%s Hundred ",ones[*num]);
    }
    else if(*count==5)
    {
        if(*num==1)
        {
            *ten_count=1;
        }
        else
        {
            *ten_count=0;
            printf("%s ",tens[*num]);
        } 
    }
    else if(*count==4)
    {
        if(num!=0 && *z_count<3)
        {
            if(*ten_count==0)
            {
                printf("%s Thousand ",ones[*num]);
            }
            else
                printf("%s Thousand ",teens[*num]);
        }
    }
    else if(*count==3)
    {
        if(num!=0 && *z_count==0)
            printf("%s Hundred ",ones[*num]);
    }
    else if(*count==2)
    {
        if(*num==1)
        {
            *ten_count=1;
        }
        else
        {
            *ten_count=0;
            printf("%s ",tens[*num]);
        }    
    }
    else if(*count==1)
    {
        if(*ten_count==0)
        {
            printf("%s",ones[*num]);
        }
        else
            printf("%s",teens[*num]);
            
    }
}

int main()
{
    int num,test,count=0,rev=0,z_count=0,ten_count=0;
    printf("Input a number: ");
    scanf("%d",&num);
    if(num == 0)
        printf("Zero");
    else
    {        
        if(num >= 0)
            test=num;
        else if(num < 0)
            test=num * -1;
        while(test>0)
        { 
            rev=rev*10+test%10;
            count++;
            test/=10;
        }
        int testc=count;
        if(count>9)
            printf("\nThe number you have entered is too large");
        else if(count<10)
        {
            if(num >= 0)
            {
                printf("\nThe number you have entered in words is:\n");
                while(testc>0 && rev>=0)
                {
                    int testn=rev%10;
                    if(testn==0)
                        z_count++;
                    else
                        z_count=0;
                    check(&testn,&testc,&z_count,&ten_count);
                    --testc;
                    rev/=10;
                }
            }
            else if(num < 0)
            {
                printf("\nThe number you have entered in words is:\nMinus ");
                while(testc>0 && rev>=0)
                {
                    int testn=rev%10;
                    if(testn==0)
                        z_count++;
                    else
                        z_count=0;
                    check(&testn,&testc,&z_count,&ten_count);
                    --testc;
                    rev/=10;
                }
            }
        }
    }
    printf("\n");
    return 0;
}