#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\typeid.cpp"
#include<bits/stdc++.h>
#include<typeinfo>
using namespace std;
class a
{

};
class b
{

};
int  main()
{
    int x;
    double y;
    char z;
    else cout<<"x is not int\n";
    cout<<typeid(x).name()<<endl;
    cout<<typeid(y).name()<<endl;
    cout<<typeid(z).name()<<endl;
    cout<<typeid(a).name()<<endl;
    return 0;
}