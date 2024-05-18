#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\J_-_Binary_Nim.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        string s;
        cin>>n>>s;
        int dee=0,dum=0;
        for(int i=0;i<n;i++)
        {
            string x;
            cin>>x;
            if(x[0]=='0')
            {
                for(int j=0;j<x.size();j++)
                {
                    if(x[j]=='0')
                    {
                        dee++;
                    }
                }
            }
            else
            {
                for(int j=0;j<x.size();j++)
                {
                    if(x[j]=='1')
                    {
                        dum++;
                    }
                }
            }
        }
        if(dee==dum)
        {
            if(s=="Dee")
            {
                cout<<"Dum"<<endl;
            }
            else
            {
                cout<<"Dee"<<endl;
            }
        }
        else
        {
            if(dee>dum)
            {
                cout<<"Dee"<<endl;
            }
            else
            {
                cout<<"Dum"<<endl;
            }
        }
    }
    return 0;
}