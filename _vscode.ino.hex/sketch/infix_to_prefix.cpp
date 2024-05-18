#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\infix_to_prefix.cpp"
#include<bits/stdc++.h>
using namespace std;
class Stack
{
    int top;
    int capacity;
    char* array;
public:
    Stack(int capacity=100)
    {
        this->capacity=capacity;
        top=-1;
        array=new char[capacity];
    }
    void push(char x)
    {
        if(top==capacity-1)
            throw out_of_range("Stack is full");
        array[++top]=x;
    }
    char pop()
    {
        if(top==-1)
            return '\0';
        return array[top--];
    }
    char peek()
    {
        if(top==-1)
            return '\0';
        return array[top];
    }
    bool isEmpty()
    {
        return top==-1;
    }
    bool isFull()
    {
        return top==capacity-1;
    }
    ~Stack()
    {
        delete[] array;
    }
};
void Swap(char& a,char& b)
{
    if(a!=b)
        a^=b^=a^=b;
}
void Reverse(string& s)
{
    int n=s.length();
    for(int i=0;i<(n+1)/2;i++)
    {
        Swap(s[i],s[n-i-1]);
        if(s[i]=='(')
            s[i]=')';
        else if(s[i]==')')
            s[i]='(';
        if(s[n-i-1]=='(')
            s[n-i-1]=')';
        else if(s[n-i-1]==')')
            s[n-i-1]='(';
    }
}
int precedence(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return -1;
}
string infix_to_postfix(string& s)
{
    Stack stack;
    string postfix;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
            stack.push(s[i]);
        else if(s[i]==')')
        {
            while(!stack.isEmpty()&&stack.peek()!='(')
            {
                postfix+=stack.pop();
            }
            if(!stack.isEmpty()&&stack.peek()!='(')
                return "Invalid Expression";
            else
                stack.pop();
        }
        else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
            postfix+=s[i];
        else
        {
            while(!stack.isEmpty()&&precedence(s[i])<=precedence(stack.peek()))
            {
                postfix+=stack.pop();
            }
            stack.push(s[i]);
        }
    }
    while(!stack.isEmpty())
    {
        postfix+=stack.pop();
    }
    return postfix;
}
string infix_to_prefix(string& s)
{
    Reverse(s);
    string postfix=infix_to_postfix(s);
    Reverse(postfix);
    return postfix;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    cout<<infix_to_prefix(s)<<endl;
    return 0;
}