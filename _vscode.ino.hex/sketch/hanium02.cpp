#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\hanium02.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class B
{
public:
    int a;
    int b;
    int add()
    {
        return a + b;
    }
    int operator+(B &x)
    {
        B tmp;
        tmp.a=this->a+x.a;
        tmp.b=this->b+x.b;
        cout<<tmp.a<<endl;
    }
};
int main()
{
    B x1, x2;
    x1.a = 10;
    x2.a = 6;
    x1 + x2;
    return 0;
}