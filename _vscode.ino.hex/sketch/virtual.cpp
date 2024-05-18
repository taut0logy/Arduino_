#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\virtual.cpp"
#include<bits/stdc++.h>
using namespace std;
class base
{
    public:
    virtual void f(){cout<<"base\n";}
    void f2() {cout<<"base 2\n";}
};
class A:public base
{
    public:
    void f(){cout<<"A\n";}
    void f2(){cout<<"A 2\n";}
};

int main()
{
    A a;
    a.f();
    //a.f2();
    base* p=&a;
    p->f();
    //p->f2();
    return 0;
}