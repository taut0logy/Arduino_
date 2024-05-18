#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\minstack.cpp"
#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int* arr;
    int max_size;
    int last;

public:
    Stack()
    {
        arr = new int[100];
        max_size = 100;
        last = -1;
    }

    Stack(int n)
    {
        arr = new int[n];
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

    int top()
    {
        if (empty()) {
            cout << "stack is empty" << endl;
            return numeric_limits<int>::min();
        }
        return arr[last];
    }

    void push(int data)
    {
        if (full()) {
            cout << "stack is full" << endl;
            return;
        }
        last++;
        arr[last] = data;
    }
    
    void pop()
    {
        if (empty()) {
            cout << "nothing to pop" << endl;
            return;
        }
        last--;
    }
};
class minstack
{
    Stack s;
    Stack min;
public:
    bool full()
    {
        return s.full();
    }
    bool empty()
    {
        return s.empty();
    }
    int top()
    {
        return s.top();
    }
    void push(int data)
    {
        s.push(data);
        if(min.empty() || data<=min.top())
        {
            min.push(data);
        }
    }
    void pop()
    {
        if(s.top()==min.top())
        {
            min.pop();
        }
        s.pop();
    }
    int minimum()
    {
        if(min.empty())
        {
            cout<<"stack is empty"<<endl;
            return numeric_limits<int>::min();
        }
        else
        return min.top();
    }
};
class maxstack
{
    Stack s;
    Stack max;
public:
    bool full()
    {
        return s.full();
    }
    bool empty()
    {
        return s.empty();
    }
    int top()
    {
        return s.top();
    }
    void push(int data)
    {
        s.push(data);
        if(max.empty() || data>=max.top())
        {
            max.push(data);
        }
    }
    void pop()
    {
        if(s.top()==max.top())
        {
            max.pop();
        }
        s.pop();
    }
    int maximum()
    {
        if(max.empty())
        {
            cout<<"stack is empty"<<endl;
            return numeric_limits<int>::min();
        }
        else
        return max.top();
    }
};

int main() 
{
    minstack s;
    s.push(200);
    s.push(450);
    s.push(60);
    s.push(90);
    s.push(10);
    s.push(5);
    cout << s.minimum() << endl;
    s.pop();
    cout << s.minimum() << endl;
    s.pop();
    cout << s.minimum() << endl;
    cout << endl;
    maxstack s1;
    s1.push(60);
    s1.push(90);
    s1.push(10);
    s1.push(5);
    s1.push(200);
    s1.push(450);
    cout << s1.maximum() << endl;
    s1.pop();
    cout << s1.maximum() << endl;
    s1.pop();
    cout << s1.maximum() << endl;
    return 0;
}