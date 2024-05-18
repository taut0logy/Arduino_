#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_1_Powering_the_Hero_easy_version.cpp"
#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b, x) for (long long i = a; i < b; i += x)
#define fr(i, a, b, x) for (long long i = a; i >= b; i -= x)
#define pb push_back
#define pf push_front
#define pp pop_back()
#define ppf pop_front()
#define vsort(v) sort(v.begin(), v.end())
#define rsort(v) sort(v.begin(), v.end(), greater<>())
#define rev(v) reverse(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define yn(flag) cout << (flag ? "YES" : "NO") << endl;
#define yout cout << "YES" << endl;
#define nout cout << "NO" << endl;
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
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
typedef set<string> sst;
typedef map<int, int> mii;
typedef map<long long, long long> mll;
typedef map<int, string> mis;
typedef map<string, int> msi;
typedef map<string, string> mss;
typedef map<char, int> mci;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<char, char> pcc;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<long long, long long> pll;
const long long M = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vl a(n);
    ll ans = 0, cnt = 0;
    priority_queue<ll> s;
    multiset<ll> m;
    vl v;
    ll ind = 0;
    f(i, 0, n, 1)
    {
        cin >> a[i];
        s.push(0);
        if (a[i] == 0)
        {
            cnt++;
            ind = i;
        }
    }

    ll pow = 0;
    f(i, 0, ind + 1, 1) if (a[i]) pow++;
    if (cnt == n)
    {
        cout << 0 << endl;
        return;
    }
    f(i, 0, n, 1)
    {
        if (a[i] == 0)
        {
            ans += s.top();
            s.pop();
            cnt--;
        }
        else
        {
            s.push(a[i]);
            /* if (pow < cnt)
            {
                s.push(a[i]);
                pow--;
            }
            else if (a[i] >= s.top())
            {
                s.push(a[i]);
                pow--;
            } */
            /*
            else
            {
                if(pow>cnt)

            } */
        }
    }
    cout << ans << endl;
    /* else
    {
        sort(all(v),gr);
        ll x=v[pow-1];
        f(i,0,n,1)
        {
            if(a[i]==0)
            {
                ans+=s.top();
                s.pop();
            }
            else
            {
                if(a[i]>=x && a[i]>s.top())
                {
                    s.push(a[i]);
                }
            }
        }
        cout<<ans<<endl;
    } */
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