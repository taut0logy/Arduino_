#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\dsa_hani.cpp"
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Stack
{
private:
    T *arr;
    int max_size;
    int last;

public:
    Stack()
    {
        arr = new T[100];
        max_size = 100;
        last = -1;
    }

    Stack(int n)
    {
        arr = new T[n];
        max_size = n;
        last = -1;
    }

    int size()
    {
        return last + 1;
    }

    bool empty()
    {
        return last == -1;
    }

    bool full()
    {
        return last == max_size - 1;
    }

    T top()
    {
        if (empty())
        {
            std::cout << "Stack is empty." << std::endl;
            return '\0';
        }
        return arr[last];
    }

    void push(T data)
    {
        if (full())
        {
            std::cout << "Stack is full." << std::endl;
            return;
        }
        last++;
        arr[last] = data;
    }

    void pop()
    {
        if (empty())
        {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        last--;
    }
};

bool balanced(const std::string &s)
{
    int n = s.size();
    Stack<char> st;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (st.empty())
            {
                return false;
            }
            char a = st.top();
            st.pop();
            if ((c == ')' && a != '(') || (c == '}' && a != '{') || (c == ']' && a != '['))
            {
                return false;
            }
        }
    }
    return st.empty();
}
int prec(char x)
{
    if (x == '^')
    {
        return 3;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else if (x == '+' || x == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
string infixtopostfix(string &s)
{
    Stack<char> st;
    int n = s.size();
    string ans;
    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            ans = ans + s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans = ans + st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(st.top()) >= prec(s[i]))
            {
                ans = ans + st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans = ans + st.top();
        st.pop();
    }
    return ans;
}
string postfixtoinfix(const string &s)
{
    Stack<string> st;
    int n = s.size();
    string ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            string c;
            c.push_back(s[i]);
            st.push(c);
        }
        else
        {
            string str1 = st.top();
            st.pop();
            string str2 = st.top();
            st.pop();
            ans = "(" + str2 + s[i] + str1 + ")";
            st.push(ans);
        }
    }
    return (ans);
}
int main()
{
    Stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    string q = "ab+cd/*";
    cout << postfixtoinfix(q) << endl;

    return 0;
}