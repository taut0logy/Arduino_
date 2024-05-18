#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\dummy3.cpp"
#include<bits./stdc++.h>
using namespace std;
class base
{
    public:
    virtual void print()
    {
        cout<<"base"<<endl;
    }
};
class derived:public base
{
    public:
    void print()
    {
        cout<<"derived"<<endl;
    }
};
class derived2:public derived
{
    public:
    void print()
    {
        cout<<"derived2"<<endl;
    }
};

int main()
{
    base *b;
    derived* d1;
    base bb;
    derived d;
    derived2 d2;
    b=&bb;
    b->print();
    b=static_cast<derived*>(&bb);
    b->print();
    b=&d2;
    b->print();
    d1=static_cast<derived*>(&bb);
    d1->print();
    return 0;
}