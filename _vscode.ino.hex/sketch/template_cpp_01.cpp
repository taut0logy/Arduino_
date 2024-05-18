#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\template_cpp_01.cpp"
#include<bits/stdc++.h>
using namespace std;
template <typename r, typename p,typename q>
r add(p a,q b)
{
    return a+b;
}
int main()
{
    int a=5;
    double b=7.8;
    float c=2.3;
    cout<<add<int>(a,b)<<endl;
    cout<<add<double>(b,c)<<endl;
    return 0;
}