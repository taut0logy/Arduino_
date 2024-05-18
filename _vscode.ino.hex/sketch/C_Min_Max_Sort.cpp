#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Min_Max_Sort.cpp"
#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b, x) for (long long i = a; i < b; i += x)
#define fr(i, a, b, x) for (long long i = a; i >= b; i -= x)
typedef long long ll;
typedef vector<long long> vl;
void solve()
{
    ll n;
    cin>>n;
    vl v(n),pos(n+1);
    ll l=(n+1)/2,r=n/2+1;
    ll ans=l;
    f(i,0,n,1)
    {
        cin>>v[i];
        pos[v[i]]=i;
    }
    if(n==1)
    {
        cout<<0<<endl;
        return;
    }
    while(l>0 && (l==r || (pos[l]<pos[l+1] && pos[r]>pos[r-1])))
    {
        //if(pos[l]>pos[l+1] || pos[r]<pos[r-1]) break;
        l--;
        r++;
        ans--;
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