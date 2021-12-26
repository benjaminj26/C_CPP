#include<bits/stdc++.h>

using namespace std;

int main()
{
    char j[100];
    int t,i,k,l;
    cout<<"Input the number of test cases: ";
    cin>>t;
    cout<<"Input "<<t<<" strings:"<<endl;
    char s[t][10];
    for(i=0;i<t;++i)
    {
        cin>>s[i];
    }
    int n1;
    cout<<"Input the names of the gem stones:"<<endl;
    cin>>j;
    int n2=strlen(j);
    for(i=0;i<t;++i)
    {
        int count=0;
        n1=strlen(s[i]);
        for(l=0;l<n1;++l)
        {
            for(k=0;k<n2;++k)
            {
                if(s[i][l]==j[k])
                    ++count;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
