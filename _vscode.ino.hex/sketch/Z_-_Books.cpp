#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Z_-_Books.cpp"
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n;
    cin>>n>>t;
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    ll ans=0,curr=0,sum=0;
    for(int i=0;i<n;i++)
    {
        while(curr<n && sum+a[curr]<=t) sum+=a[curr++];
        if(sum<=t) ans=max(ans,curr-i);
        sum-=a[i];
    }
    cout<<ans<<endl;
    return 0;
}