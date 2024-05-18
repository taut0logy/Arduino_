#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Fighting_Tournament.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n,q;
    cin>>n>>q;
    map<ll,ll> m;
    vector<vector<ll>> v(n+1);
    deque<ll> a(n);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]=i+1;
    }
    for(ll i=0;i<n;i++)
    {
        ll x=a.front();
        a.pop_front();
        ll y=a.front();
        a.pop_front();
        if(x>y)
        {
            v[m[x]].push_back(i+1);
            a.push_front(x);
            a.push_back(y);
        }
        else
        {
            v[m[y]].push_back(i+1);
            a.push_front(y);
            a.push_back(x);
        }
    }
    for(int i=0;i<q;i++)
    {
        ll x,k;
        cin>>x>>k;
        ll ans=upper_bound(v[x].begin(),v[x].end(),k)-v[x].begin();
        if(x==m[n] && k>=n) ans+=k-n;
        cout<<ans<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
