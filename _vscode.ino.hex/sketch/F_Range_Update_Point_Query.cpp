#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\F_Range_Update_Point_Query.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum(ll n)
{
    int s = 0;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}
void solve()
{
    int n,q;
    cin>>n>>q;
    ll a[n+1];
    set<int>idx;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>9) idx.insert(i);
    }
    for(int j=0;j<q;j++)
    {
        ll y,l,r,z;
        cin>>y;
        if(y==1)
        {
            cin>>l>>r;
            auto x=idx.lower_bound(l);
            while(x!=idx.end() && *x<=r)
            {
                a[*x]=sum(a[*x]);
                if(a[*x]<10) idx.erase(x++);
                else x++;
            }
        }
        else
        {
            cin>>z;
            cout<<a[z]<<endl;
        }
    }
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