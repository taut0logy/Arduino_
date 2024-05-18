#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\diamond_problem_solution.cpp"
#include <bits/stdc++.h>
using namespace std;
class A {
public:
    int x;
};

class B : virtual public A {
public:
    virtual void foo() {
        x = 10;
    }
};

class C : virtual public A {
public:
    virtual void foo() {
        x = 20;
    }
};

class D : public B, public C {
public:
    void bar() {
        // There is only one version of x now.
        x = 30;
    }
};
int main()
{
    D d;
    d.bar();
    //d.foo();
    return 0;
}