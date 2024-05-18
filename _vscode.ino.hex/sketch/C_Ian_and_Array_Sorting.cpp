#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Ian_and_Array_Sorting.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n,cnt=0,mx=INT_MIN,mn=INT_MAX;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        mx=max(mx,v[i]);
        mn=min(mn,v[i]);
    }
    if(n==2)
    {
        if(v[0]<=v[1]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    for(int i=n-1;i>0;i--)
    {
        ll diff=v[i-1]-v[i];
        if(diff>0 && i-1==0)
        {
            cout<<"NO"<<endl;
            return;
        }
        if(diff>0)
        {
            v[i-2]-=diff;
        }
        else
        {
            if(i-2>=0) v[i-2]+=abs(diff);
        }
        i--;
    }
    cout<<"YES"<<endl;
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