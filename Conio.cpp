/*
    This is a simple program to test conio.h
    Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<iostream>

using namespace std;

int main()
{
    cout<<"Enter your name: ";
    char a[8];
    // for(int i=0;i<=8;i++)
    // {
    //     b=getchar();
    //     a[i]=b;
    // }
    cin>>a;
    cout<<a<<" is the name you typed"<<endl;
    return 0;
}