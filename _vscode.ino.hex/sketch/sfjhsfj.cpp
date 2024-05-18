#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\sfjhsfj.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modInverse(ll c, ll k)
{
    ll m = k;
    ll y = 0, x = 1;

    while (c > 1)
    {
        ll q = c / k;
        ll t = k;

        k = c % k;
        c = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
    {
        x += m;
    }

    return x;
}
ll modgcd(ll a,ll b,ll &x,ll &y)
{
    if(a==0)
    {
        x=0;
        y=1;
        return b;
    }
    ll m=modgcd(b%a,a,x,y);
    ll temp=x;
    x=y-(b/a)*x;
    y=temp;
    return m;
}
void solve()
{
    ll k,c;
    cin>>k>>c;
    if(c==1)
    {
        cout<<k+1<<endl;
        return;
    }
    if(c>k)
    {
        if(k==1)
        {
            cout<<1<<endl;
            return;
        }
    }
    if(k%c==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    ll x,y;
    ll m=modgcd(c,k,x,y);
    if(m==1)
    {
        ll ans=(x%k+k)%k;
        cout<<ans<<endl;
        return;
    }
    cout<<"IMPOSSIBLE"<<endl;
    
    /* x=modInverse(c,k);
    cout<<x<<endl;
    if(x<0)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    ll ans=(x%k+k)%k;
    cout<<ans<<endl; */
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}