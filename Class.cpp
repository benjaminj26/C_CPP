/*
    Program to show use cases of classes in C++
    Author: Benjamin Joseph
    Date  : 22-08-2021
*/

#include<iostream>
#include<cstring>
#include<fstream>
#include<unistd.h>
#include<cstdlib>

using namespace std;

class College
{
    public:
        int rno;
        char branch[20];
        char usrname[20];
        char passwd[20];
        void sign_up()
        {
            cout<<"Input Roll Number: ";
            cin>>rno;
            cin.ignore();
            cout<<"Input Branch: ";
            cin>>branch;
            cout<<"Input your username: ";
            cin>>usrname;
            char *pass=getpass("Password: ");
            strcpy(passwd,pass);
            cout<<"\nAccount created successfully\n";
        }
        int sign_in()
        {
            char un[20],pw[20];
            cout<<"\nInput your username: ";
            cin>>un;
            char *pass=getpass("Password: ");
            strcpy(pw,pass);
            if(strcmp(usrname,un)==0 && strcmp(passwd,pw)==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        void display()
        {
            cout<<"\nRoll Number: "<<rno<<endl;
            cout<<"\nBranch: "<<branch<<endl;
        }
};

int main(int argc, char *argv[])
{
    College c,d;
    if(strcmp(argv[1],"signup")==0)
    {
        ofstream out("Trial.bin",ios::binary);
        c.sign_up();
        // c.sign_in();
        out.write((char *)&c,sizeof(c));
        out.close();
        // c.display();
    }
    else if(strcmp(argv[1],"signin")==0)
    {
        ifstream in("Trial.bin",ios::binary);
        in.read((char *)&d,sizeof(d));
        in.close();
        int n=d.sign_in();
        if(n==1)
            d.display();
        else 
            cout<<"The username and password that you entered do not match"<<endl;
    }
    return 0;
}