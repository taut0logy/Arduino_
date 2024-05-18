#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Update_Files.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n,k,ans=0,x=0,z=1;
    cin>>n>>k;
    if(n==1) {cout<<0<<endl; return;}
    while(1)
    {
        ll m=pow(2,x);
        z+=min(k,m);
        x++;
        ans++;
        if(z>=n || m>=k) break;
    }
    n=((n-z>0)?(n-z):0);
    ans+=ceil(n*1.0/k);
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