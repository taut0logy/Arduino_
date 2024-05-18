#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\lab.cpp"
#include<bits/stdc++.h>
using namespace std;

class a
{
    int x;
    public:
    a(int n)
    {
        x=n;
    }
    friend int getmax( a obj1,a obj2);
};

int getmax(a obj1,a obj2)
{
    return (obj1.x>obj2.x)?obj1.x:obj2.x;
}

int main()
{
    a o1(5);
    a o2(6);
    cout<<getmax(o1,o2);
    return 0;
}