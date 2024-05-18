#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\D_Epic_Transformation.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin >> n;
    map<ll,ll> m;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        m[x]++;
    }
    priority_queue<pair<ll,ll>> q;
    for(auto x:m)
    {
        q.push({x.second,x.first});
    }
    ll cnt=0;
    while(q.size()>1)
    {
        pair<ll,ll> a=q.top();
        q.pop();
        pair<ll,ll> b=q.top();
        q.pop();
        cnt+=2;
        if(a.first-1)
        {
            q.push({a.first-1,a.second});
        }
        if(b.first-1)
        {
            q.push({b.first-1,b.second});
        }
    }
    cout<<n-cnt<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    int test = t;
    while (t--)
    {
        solve();
    }
    return 0;
}