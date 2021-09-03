/*
    Program to show use cases of classes in C++
    Author: Benjamin Joseph
    Date  : 22-08-2021
*/

#include<iostream>
#include<cstring>
#include<fstream>
#include<unistd.h>

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
        void sign_in()
        {
            char un[20],pw[20];
            cout<<"\nInput your username: ";
            cin>>un;
            char *pass=getpass("Password: ");
            strcpy(pw,pass);
            if(strcmp(usrname,un)==0 && strcmp(passwd,pw)==0)
                cout<<"\nSIGN IN SUCCESSFUL"<<endl;
            else
                cout<<"\nThe username and password do not match!!\n";
        }
        void display()
        {
            cout<<"\nRoll Number: "<<rno;
            cout<<"\nBranch: "<<branch;
        }
};

int main(int argc, char *argv[])
{
    College c,d;
    if(strcmp(argv[1],"write")==0)
    {
        ofstream out("Trial.bin",ios::binary);
        c.sign_up();
        c.sign_in();
        out.write((char *)&c,sizeof(c));
        out.close();
        c.display();
    }
    else if(strcmp(argv[1],"read")==0)
    {
        ifstream in("Trial.bin",ios::binary);
        in.read((char *)&d,sizeof(d));
        in.close();
        d.display();
    }
    return 0;
}