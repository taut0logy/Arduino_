#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\ccc.cpp"
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
mll prime_factor(ll a)
{
    mll m;
    while (a % 2 == 0)
    {
        m[2]++;
        a /= 2;
    }
    for (ll i = 3; i * i <= a; i += 2)
    {
        while (a % i == 0)
        {
            m[i]++;
            a /= i;
        }
    }
    if (a > 2)
        m[a]++;
    return m;
}

vl divisors(ll a)
{
    vl v;
    for(ll i=1;i*i<=a;i++)
    {
        if(a%i==0)
        {
            v.pb(i);
            if(i*i!=a) v.pb(a/i);
        }
    }
    return v;
}
ll n,m;
vector<string> s;
map<string,int> t;
string find(int cur,int v,string q,vector<string> s,map<string,int> t)
{
    if(cur==n-1)
    {
        q+=s[cur];
        if(q.size()>=3 && !t[q])
        {
            cout<<q<<endl;
            exit(0);
        }
    }
    else
    {
        q+=s[cur]+"_";
        for(int i=0;i<=v;i++)
        {
            find(cur+1,v-i,q,s,t);
            q+="_";
        }
    }
}
void solve()
{
    cin>>n>>m;
    int mx=n-1
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        s.pb(x);
        mx+=x.size();
    }
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        t[x]++;
    }
    sort(all(s));
    int mx=n-1;
    for(int i=0;i<n-1;i++)
    {
        mx-=m-s[i].size();
    }
    if(16-mx<0)
    {
        cout<<-1<<endl;
        return;
    }
    while(next_permutation(all(s)))
    {
        find(0,16-mx,"",s,t);
    }
    //dfs(0,16-mx,"",s,t);
    cout<<-1<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin >> t;
    int test = t;
    while (t--)
    {
        solve();
    }
    return 0;
}