#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\cc.cpp"
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define vpi vector<pi>
#define pb push_back
#define ff first
#define ss second
#define ld long double
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
using namespace std;

const ll mod=1e9+7;
const ll inf=1e15;
const ll mod2=998244353;

void solve()
{
    int n,k;
    cin>>n>>k;
    vpi a(n);
    for(int i=0;i<n;i++) cin>>a[i].ff;
    for(int i=0;i<n;i++) cin>>a[i].ss;

    sort(a.begin(),a.end());

    for(int i=n-2;i>=0;i--)
    {
        a[i].ss=min(a[i].ss,a[i+1].ss);
    }
    int reduce=0;
    int idx=0;
    while(idx<n)
    {
        while(idx<n)
        {
            if(a[idx].ff-reduce<=k)
            {
                idx++;
            }
            else break;
        }
        if(a[idx].ff>0 && k<=0)
        {
            no;
            return ;
        }
        if(idx<n)
        {
            reduce+=k;
            k-=a[idx].ss;
        }
    }
    cout<<"YES\n";
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