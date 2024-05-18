#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\X_-_Row_GCD.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll a[n];
    ll g=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(ll i=1;i<n;i++)
    {
        g=__gcd(g,a[i]-a[i-1]);
    }
    for(ll i=0;i<m;i++)
    {
        ll y;
        cin>>y;
        cout<<__gcd(g,y+a[0])<<" ";
    }
    return 0;
}