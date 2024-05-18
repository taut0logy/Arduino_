#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Hossam_and_Friends.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long M=1e9+7;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<ll> v(n+5,n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        v[a]=min(v[a],(ll)(b-1));
    }
    ll ans=0;
    for(int i=n;i>0;i--)
    {
        v[i]=min(v[i],v[i+1]);
        ans+=v[i]-i+1;
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
    while (t--)
    {
        solve();
    }
    return 0;
}