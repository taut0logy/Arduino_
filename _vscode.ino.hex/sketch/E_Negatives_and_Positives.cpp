#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\E_Negatives_and_Positives.cpp"
#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b, x) for (long long i = a; i < b; i += x)
#define fr(i, a, b, x) for (long long i = a; i >= b; i -= x)
#define ff(x, m) for (auto x : m)
#define pb push_back
#define pf push_front
#define pp pop_back()
#define ppf pop_front()
#define vsort(v) sort(v.begin(), v.end())
#define rsort(v) sort(v.begin(), v.end(), greater<>())
#define rev(v) reverse(v.begin(), v.end())
#define yn(flag) cout << (flag ? "YES" : "NO") << endl;
#define yout cout << "YES" << endl;
#define nout cout << "NO" << endl;
#define bc back()
#define bg begin()
#define en end()
#define gr greater<>()
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef set<ll> sl;
typedef set<int> si;
typedef set<char> sc;
typedef map<int, int> mii;
typedef map<long long, long long> mll;
typedef map<int, string> mis;
typedef map<string, int> msi;
typedef map<string, string> mss;
typedef map<char, int> mci;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, char> pcc;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<long long, long long> pll;
void solve()
{
    ll n;
    cin>>n;
    ll sum=0,cnt=0;
    ll a[n];
    f(i,0,n,1)
    {
        cin>>a[i];
        if(a[i]<0)
        {
            cnt++;
            a[i]*=-1;
        }
        sum+=a[i];
    }
    sort(a,a+n);
    if(!(cnt&1))
    {
        cout<<sum<<endl;
        return;
    }
    cout<<sum-2*a[0]<<endl;
    /* f(i,0,n-1,1)
    {
        if(a[i]<0 && a[i+1]<0)
        {
            a[i]*=-1;
            a[i+1]*=-1;
            sum+=2*(a[i]+a[i+1]);
        }
    }
    f(i,0,n-1,1)
    {
        if(a[i]<0 && a[i+1]==0)
        {
            sum+=2*(-1*a[i]-a[i+1]);
            a[i]*=-1;
            a[i+1]*=-1;
        }
        if(a[i+1]<0 && a[i]==0)
        {
            sum+=2*(-1*a[i+1]-a[i]);
            a[i]*=-1;
            a[i+1]*=-1;
        }
        if(a[i]<0 && a[i+1]>0 && -1*a[i]>a[i+1])
        {
            sum+=2*(-1*a[i]-a[i+1]);
            a[i]*=-1;
            a[i+1]*=-1;
        }
        if(a[i+1]<0 && a[i]>0 && -1*a[i+1]>a[i])
        {
            sum+=2*(-1*a[i+1]-a[i]);
            a[i]*=-1;
            a[i+1]*=-1;
        }
    } 
    cout<<sum<<endl; */
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