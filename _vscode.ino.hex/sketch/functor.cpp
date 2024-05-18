#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\functor.cpp"
#include<bits/stdc++.h>
using namespace std;
class increment
{
    public:
    int operator()(int a)
    {
        return a+1;
    }
};
int main()
{
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    transform(a,a+n,a,increment());
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}