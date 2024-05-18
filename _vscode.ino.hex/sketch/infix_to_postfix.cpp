#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\infix_to_postfix.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Stack
{
public:
    int top;
    int size;
    char *arr;
    Stack(int n=100)
    {
        size = n;
        top = -1;
        arr = new char[size];
    }
    bool empty()
    {
        return top == -1;
    }
    bool full()
    {
        return top == size - 1;
    }
    void push(char x)
    {
        if (full())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    char Top()
    {
        if (empty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top];
    }
};

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string infixtopostfix(string &s)
{
    Stack st;
    int n = s.size();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= '0' && s[i] <= '9'))
        {
            ans = ans + s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.Top() != '(')
            {
                ans = ans + st.Top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(st.Top()) >= prec(s[i]))
            {
                ans = ans + st.Top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans = ans + st.Top();
        st.pop();
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    string ans = infixtopostfix(s);
    cout << ans << endl;

    return 0;
}