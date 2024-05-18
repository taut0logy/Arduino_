#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Get_the_Containers.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> v(n);
    ll l=0,r;
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
        r+=v[i];
        l=max(l,v[i]);
    }
    while(l<r)
    {
        ll mid = (l+r)/2;
        ll sum = 0;
        ll cnt = 1;
        for(ll i=0;i<n;i++)
        {
            if(sum+v[i]<=mid)
                sum+=v[i];
            else
            {
                cnt++;
                sum = v[i];
            }
        }
        if(cnt<=m)
            r = mid;
        else
            l = mid+1;
    }
    cout<<l<<endl;
   
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Test,TT = 0;
    cin >> Test;
    while (TT++<Test)
    {
        cout<<"Case "<<TT<<": ";
        solve();
    }
    return 0;
}