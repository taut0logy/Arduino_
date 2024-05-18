#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\numerical001.cpp"
#include<bits/stdc++.h>
using namespace std;

void calc(string s,int& a1,int& b1,int& c1,int& d1)
{

    int sign,start,end;
    if(s[0]=='-')
        sign=-1;
    else
        sign=1;
    if(s[1]=='x')
        a1=sign;
    else if(s[1]=='y')
        b1=sign;
    else if(s[1]=='z')
        c1=sign;
    else
        d1=sign;
    for(int i=2;i<s.size();i++)
    {
        if(s[i]=='x')
        {
            if(s[i-1]=='+')
                a1+=sign;
            else
                a1-=sign;
        }
        else if(s[i]=='y')
        {
            if(s[i-1]=='+')
                b1+=sign;
            else
                b1-=sign;
        }
        else if(s[i]=='z')
        {
            if(s[i-1]=='+')
                c1+=sign;
            else
                c1-=sign;
        }
        else if(s[i]==')')
        {
            if(s[i-1]=='+')
                d1+=sign;
            else
                d1-=sign;
        }
        else if(s[i]=='+')
            sign=1;
        else if(s[i]=='-')
            sign=-1;
    }
}


int main()
{
    int n,itr=0;
    vector<string> equations(3);
    cout<<"Enter the three equations: "<<endl;
    for(int i=0;i<3;i++)
    {
        string s;
        cin>>s;
        s.push_back(')');
        equations.push_back(s);

    }
    int nn=n+1;
    int a1,b1,c1,d1,a2,b2,c2,d2,a3,b3,c3,d3;
        calc(equations[0],a1,b1,c1,d1);
        calc(equations[1],a2,b2,c2,d2);
        calc(equations[2],a3,b3,c3,d3);
        cout<<a1<<' '<<b1<<' '<<c1<<' '<<d1<<endl;
        cout<<a2<<' '<<b2<<' '<<c2<<' '<<d2<<endl;
        cout<<a3<<' '<<b3<<' '<<c3<<' '<<d3<<endl;
    double x=9,x1=0,y=9,y1=0,z=9,z1=0;
    while(abs(x-x1)>0.0001 || abs(y-y1)>0.0001 || abs(z-z1)>0.0001)
    {
        x=x1;
        y=y1;z=z1;
        x1=(d1-b1*y-c1*z)/a1;
        y1=(d2-a2*x-c2*z)/b2;
        z1=(d3-a3*x-b3*y)/c3;
        itr++;
    }
    cout<<a1<<' '<<a2<<' '<<a3<<endl;
    cout<<"The solution is: "<<endl;
    cout<<"x = "<<x1<<endl;
    cout<<"y = "<<y1<<endl;
    cout<<"z = "<<z1<<endl;
    cout<<"Number of iterations: "<<itr<<endl;
    return 0;
}
