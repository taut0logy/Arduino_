#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\prefix_expression_evaluation.cpp"
#include<bits/stdc++.h>
using namespace std;
int solve(string &s)
{
    stack<int>st;
    int ans;
    int size=s.size();
    for(int i=size-1;i>=0;i--)
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