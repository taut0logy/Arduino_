#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\namespace.cpp"
#include<bits/stdc++.h>
namespace a
{
    void f(){std::cout<<"namespace a\n";}
}
namespace b
{
    void f(){std::cout<<"namespace b\n";}
}
namespace test
{
    using namespace std;
    int m=10;
    void display(int n)
    {
        cout<<n;

    }
}

int m=5;
using namespace test;
int main()
{
    //std::cout<<"namespaces:\n"
    //f();
    cout<<test::m<<endl;
}