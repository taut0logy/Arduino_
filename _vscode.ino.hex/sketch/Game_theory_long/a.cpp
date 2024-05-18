#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Game_theory_long\\a.cpp"
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
        }
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            int y=abs(a[i]-x)-1;
            ans^=y;
        }
        cout<<"Case "<<cs<<": ";
        cout<<(ans?"white wins":"black wins")<<endl;
    }
    return 0;
}