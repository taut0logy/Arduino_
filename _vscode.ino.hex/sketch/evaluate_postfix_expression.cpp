#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\evaluate_postfix_expression.cpp"
#include<bits/stdc++.h>
using namespace std;
int evaluate_postfix_expression(string s)
{
    stack<int>st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();
            switch(s[i])
            {
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1-op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                case '^':
                    st.push(pow(op1,op2));
                    break;
            }
        }
    }
    return st.top();
}
int main()
{
    string s;
    cin>>s;
    cout<<evaluate_postfix_expression(s)<<endl;
}