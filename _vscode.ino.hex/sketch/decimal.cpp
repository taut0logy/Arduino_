#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\decimal.cpp"
#include <bits/stdc++.h>
using namespace std;
void binary(int x)
{
    if(x==0)
    {
        cout<<0;
        return;
    }
    if(x==1)
    {
        cout<<1;
        return;
    }
    binary(x/2);
    cout<<x%2;
}
int main()
{
    int n;
    cin>>n;
    binary(n);
    return 0;
}