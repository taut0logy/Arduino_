#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\inheritance_slide.cpp"
#include<bits/stdc++.h>
using namespace std;
class base
{
    public:
    virtual void f(){cout<<"base::f()"<<endl;}
};
class d1:public base
{
    public:
    void f(){cout<<"d1::f()"<<endl;}
};
class d2:public d1
{
    public:
    void f(){cout<<"d2::f()"<<endl;}
};
class d3:public d2{};
class d4:public d3{};
int main()
{
    d4 d;
    base &p=d;
    p.f();
    return 0;
}