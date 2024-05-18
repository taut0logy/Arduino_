#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\template_slide.cpp"
#include<bits/stdc++.h>
using namespace std;
template<typename r,typename p,typename q>
r add(p a,q b)
{
    return a+b;
}
int main()
{
    int a=5;
    float c=2.8;
    double b=7.6;
    cout<<add<float,int>(b,c)<<endl;
    return 0;
}