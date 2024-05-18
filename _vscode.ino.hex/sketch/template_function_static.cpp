#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\template_function_static.cpp"
#include<bits/stdc++.h>
using namespace std;
template<class T>
void func(const T &x)
{
    static int count=0;
    cout<<"x="<<x<<"count="<<count++<<endl;
    return;
}
int main()
{
    func<int>(1);
    func<int>(2);
    func<double>(1.1);
    func<int>(3);
    func<double>(2.2);
    func<float>(1.1);
    return 0;
}