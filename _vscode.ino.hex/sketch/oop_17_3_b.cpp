#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\oop_17_3_b.cpp"
#include<bits/stdc++.h>
using namespace std;

class a1
{
public:
    a1(int x) { cout<<"A1 :: A1(int) called"<<endl; }
};

class a2: public a1
{
public:
    a2(int x):a1(x) { cout<<"A2 :: A2(int) called"<<endl; }
};

class a3: public a1
{
public:
    a3(int x):a1(x) { cout<<"A3 :: A3(int) called"<<endl; }
};

class a4: virtual public a2
{
public:
    a4(int x):a2(x) { cout<<"A4 :: A4(int) called"<<endl; }
};

class a5: virtual public a3
{
public:
    a5(int x):a3(x) { cout<<"A5 :: A5(int) called"<<endl; }
};

class a6: public a4, public a5
{
public:
    a6(int x):a2(x),a3(x),a4(x),a5(x) { cout<<"A6 :: A6(int) called"<<endl; }
};

int main()
{
    a6 obj(30);
    return 0;
}