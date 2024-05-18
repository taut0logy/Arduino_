#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\R_-_Again_Stone_Game.cpp"
#include<bits/stdc++.h>
using namespace std;
int Grundy(int n)
{
    if(n==1) return 0;
    if(!(n&1)) return n;
    n--;
    Grundy(n/2);
}
int main()
{
    int T;
    cin>>T;
    int cs=0;
    while(cs++<T)
    {
        int n,ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            ans^=Grundy(x);
        }
        if(ans) cout<<"Case "<<cs<<": Alice"<<endl;
        else cout<<"Case "<<cs<<": Bob"<<endl;
    }
    return 0;
}