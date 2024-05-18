#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\nwe.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class A
{
public:
    A(int a)
    {
        cout << "base a\n";
    }
};

class B
{
public:
    B(int a)
    {
        cout << "base b\n";
    }
};

class C : protected A, private B
{
public:
    C(int a) : A(a), B(a)
    {
        cout << "derived c\n";
    }
};

class D : protected C
{
public:
    D(int a) : C(a)
    {
        cout << "derived d\n";
    }
};

int main()
{
    C c(10);
    B d(5);
    D e(5);
    return 0;
}