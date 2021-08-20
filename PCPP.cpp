/*
    This is a C++ program to print the prime numbers in a range given by the user
    Author: Benjamin Joseph
    Date: 03/07/2021
*/
#include<iostream>

using namespace std;

int main()
{
    cout<<"Input the lower limit: ";
    int low;cin>>low;
    cout<<"Input the upper limit: ";
    int upp;cin>>upp;
    for(int i=low;i<upp;i+=1)
    {
        int flag=0;
        for(int j=2;j<(i+1)/2;j+=1)
        {
            if(i%j==0)
                flag+=1;
        }
        if(flag==0 && i!=1 && i!=4)
            cout<<i<<endl;
    }
    return 0;
}