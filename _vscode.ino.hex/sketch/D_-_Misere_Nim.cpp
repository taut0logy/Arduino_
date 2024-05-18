#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\D_-_Misere_Nim.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int cs=0;
    while(cs++<T)
    {
        int n,ans=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            ans^=a[i];
        }
        
        cout<<"Case "<<cs<<": ";
        cout<<(!ans?"Alice":"Bob")<<endl;
    }
    return 0;
}