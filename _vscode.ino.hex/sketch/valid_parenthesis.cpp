#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\valid_parenthesis.cpp"
#include<bits/stdc++.h>
using namespace std;
bool valid(string st)
{
    stack<char> s;
    for(int i=0;i<s.size();i++)
    {
        if(st[i]=='(' || st[i]=='{' || st[i]=='[')
        {
            s.push(st[i]);
        }
        else if(st[i]==')' || st[i]=='}' || st[i]==']')
        {
            if(s.empty())
            {
                return false;
            }
            else if(s.top()=='(' && st[i]==')')
            {
                s.pop();
            }
            else if(s.top()=='{' && st[i]=='}')
            {
                s.pop();
            }
            else if(s.top()=='[' && st[i]==']')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
}
int main()
{
    string st;
    cin>>st;
    cout<<(valid(st)?"valid":"invalid")<<endl;
}