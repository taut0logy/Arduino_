#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\dynamic_cast.cpp"
#include<bits/stdc++.h>
using namespace std;
class B
{
    public:
    virtual void f(){cout<<"Base\n";}
};
class D:public B
{
    public:
    void f(){cout<<"Derived\n";}
};
int main()
{
    B *bp,b;
    D *dp,d;
    bp=dynamic_cast<B*> (&d);
    if(dp) 
    {
        cout<<"D* to B*\n";
        bp->f();
    }
    else cout<<"hoynai\n";
    

}