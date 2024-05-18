#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Candy_Store.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}
void solve()
{
    ll n,ans=0;
    cin>>n;
    ll a[n],b[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>b[i];
    }
    ll x,y,i=0;
    while(i<n)
    {
        x=a[i]*b[i];
        y=b[i];
        ll j;
        for(j=i+1;j<n;j++)
        {
            x=__gcd(x,a[j]*b[j]);
            y=lcm(y,b[j]);
            //j++;
           if(x%y!=0)
               break;
        }
        ans++;
        i=j;
    }
    cout<<ans<<endl;
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