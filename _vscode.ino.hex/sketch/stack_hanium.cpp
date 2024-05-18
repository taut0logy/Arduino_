#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\stack_hanium.cpp"
#include<bits/stdc++.h>
using namespace std;
bool isbalanced(string &s)
{
    stack<char>st;
    int size=s.size();
    for(int i=0;i<size;i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty())
            {
                return false;
            }
            else if(s[i]==')')
            {
                if(st.top()!='(')
                {
                    return false;
                }
                st.pop();
            }
            else if(s[i]=='}')
            {
                if(st.top()!='{')
                {
                    return false;
                }
                st.pop();
            }
            else if(s[i]==']')
            {
                if(st.top()!='[')
                {
                    return false;
                }
                st.pop();
            }
        }
    }
    return st.empty();
}
int solve(string &s)
{
    stack<int>st;
    int ans;
    int size=s.size();
    for(int i=0;i<size;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
           int a=st.top();
           st.pop();
           int b=st.top();
           st.pop();
           if(s[i]=='+')
           {
              ans=a+b;
           }
           else if(s[i]=='-')
           {
            ans=abs(a-b);
           }
           else if(s[i]=='*')
           {
            ans=a*b;
           }
           else 
           {
            ans=a/b;
           }
           st.push(ans);
        }
    }
    return st.top();

}

int main()
{
    string s;
    cin>>s;
    int n=solve(s);
    cout<<n;
    
    return 0;
}