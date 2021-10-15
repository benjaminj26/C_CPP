/*
    This is a C++ program that accepts a number from the user and checks whether it is a prime number o  
    Author: Benjamin Joseph
    Date: 08/07/2021
*/
#include<iostream>

using namespace std;

int main()
{
    cout<<"Enter a number: ";
    int n,flag=0,ch;
    cin>>n;
    for(int i=2;i<(n+1)/2;i++)
    {
        if(n%i==0)
         flag++;
    }
    if(flag==0 && n!=4)
        cout<<n<<" is prime\n";
    else
        cout<<n<<" is not prime\n";
    return 0;
}