#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\inheritance_example.cpp"
#include<bits/stdc++.h>
using namespace std;
class ground
{
    int rooms;
    protected:
    void put()
    {
        cout<<"put rooms";
    }
    public:
    void get()
    {
        cout<<"get rooms";
    }
};
class middle:private ground
{
    int labs;
    public:
    void take()
    {
        cout<<"take floors";
    }
    void give()
    {
        cout<<"give floors";
    }
};
class top:public middle
{ 
    int roof;
    public:
    void in()
    {
        cout<<"in roof";
    }
    void out()
    {
        cout<<"out roof";
    }
};
int main()
{

    top t;
    t.put();
    t.get();
    t.take();
    t.give();
    t.in();
    t.out();
    return 0;
}