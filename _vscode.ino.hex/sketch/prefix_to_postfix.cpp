#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\prefix_to_postfix.cpp"
#include<bits/stdc++.h>
using namespace std;
string prefixtopostfix(string &s)
{
    stack<string>st;
    int n=s.size();
    string ans;
    for(int i=n-1;i>=0;i--)
    {
        char c=s[i];
        if(c>='a' && c<='z')
        {
            string ss;
            ss+=c;
            st.push(ss);
        }
        else
        {
            string str1=st.top();
            st.pop();
            string str2=st.top();
            st.pop();
            string sign;
            sign+=c;
            string ans="("+str1+sign+str2+")";
            st.push(ans);
        }
    }
    ans=st.top();
    return ans;
}
string postfixtoprefix(string &S)
{
    stack<string>st;
    int n=S.size();
    string ans;
    for(int i=0;i<n;i++)
    {
        char c=S[i];
        if(c>='a' && c<='z')
        {
            string ss;
            ss+=c;
            st.push(ss);
        }
        else
        {
            string str1=st.top();
            st.pop();
            string str2=st.top();
            st.pop();
            string sign;
            sign+=c;
            string ans="("+str2+sign+str1+")";
            st.push(ans);
        }
    }
    ans=st.top();
    return ans;
}
int main()
{
    string s;
    cin>>s;
    string ans=prefixtopostfix(s);
    cout<<ans<<endl;

    return 0;
}