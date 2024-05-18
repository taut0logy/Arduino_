#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Trailing_Zeroes_III.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin>>n;
    ll ans = 0;
    ll lo = 0,hi = 1e9;
    while(lo<=hi)
    {
        ll mid = (lo+hi)/2;
        ll temp = mid;
        ll cnt = 0;
        while(temp)
        {
            cnt+=temp/5;
            temp/=5;
        }
        if(cnt==n)
        {
            ans = mid;
            hi = mid-1;
        }
        else if(cnt>n)
            hi = mid-1;
        else
            lo = mid+1;
    }
    if(ans==0)
        cout<<"impossible"<<endl;
    else
        cout<<ans<<endl;
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