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

void hasher(char *str, char *encrypted)
{
    char hash[]=
    {
        '#','u','i','g','l','t','<','o','d','?','S','k','y','r','s','/','a','z','c','p','x','v',',',
        'j','f','n','q','e','Z','w','m','>','b','h','`','5','H','1','9','2','~','A','7','4','8','3','0','6','.',
        '_','%','^','-','*','=','$','@','#','+','&','!','K',
        'Y','L','C','W','R','J','G','N','X','D','B','V','O','Q','E','I','F','U','P','T','\0'
    };
    char letters[]=
    {
        ' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
        'r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9',
        '!','@','#','$','%','^','&','&','*','/','?','>','~','`','<',',','.',
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
        'O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'
    };
    size_t size = strlen(str);
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<strlen(letters);++j)
        {
            if(str[i]==letters[j])
            {
                encrypted[i]=hash[j];
            }
        }
    }
    encrypted[size]='\0';
}

class College
{
    private:
        int rno;
        char branch[20];
        char passwd[20];
        int marks[5];
        char phone[11];
        char aadhar[15];

    public:
        char usrname[20];
        void sign_up()
        {
            cout<<"Input your username: ";
            cin>>usrname;
            char *pass=getpass("Input your password: ");
            hasher(pass,passwd);
            cout<<"\nAccount created successfully\n";
            cout<<"Input Roll Number: ";
            cin>>rno;
            cin.ignore();
            cout<<"Input Branch: ";
            cin>>branch;
            cout<<"Input your phone number: ";
            cin>>phone;
            cin.ignore();
            cout<<"Input your aadhar number: ";
            cin.getline(aadhar,15);
            free(pass);
            
        }
        int sign_in()
        {
            char un[20],pw[20];
            cout<<"Username: ";
            cin>>un;
            char *pass=getpass("Password: ");
            hasher(pass,pw);
            if(strcmp(usrname,un)==0 && strcmp(passwd,pw)==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            free(pass);
        }
        void display()
        {
            cout<<"Roll Number: "<<rno<<endl;
            cout<<"Branch: "<<branch<<endl;
            cout<<"Phone Number: "<<phone<<endl;
            cout<<"Aadhar Number: "<<aadhar<<endl;
        }
};

int main(int argc, char *argv[])
{
    College c,d;
    if(argc <= 1)
        printf("\nToo few arguments!!\n\n");
    else
    {
        if(strcmp(argv[1],"signup")==0)
        {
            ofstream out("Files/Class.bin",ios::binary);
            c.sign_up();
            out.write((char *)&c,sizeof(c));
            out.close();
        }
        else if(strcmp(argv[1],"signin")==0)
        {
            ifstream in("Files/Class.bin",ios::binary);
            in.read((char *)&d,sizeof(d));
            in.close();
            int n=d.sign_in();
            if(n==1)
                d.display();
            else 
                cout<<"The username and password that you entered do not match"<<endl;
        }
    }
    return 0;
}