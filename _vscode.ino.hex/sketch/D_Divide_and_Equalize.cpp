#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\D_Divide_and_Equalize.cpp"
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define pp pop_back()
#define ppf pop_front()
#define rev(v) reverse(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define yn(flag) cout << (flag ? "YES" : "NO") << endl;
#define yout cout << "YES" << endl
#define nout cout << "NO" << endl
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define fr front()
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
typedef pair<string, long long> psl;
typedef pair<long long, long long> pll;
const long long M=1e9+7;
const long long INF=1e18;
const long long N=1e5+5;
const double pi=acos(-1);
const double eps=1e-9;
const long long mod=998244353;
const int MAXN = 1000000;
bitset<MAXN + 1> sieve;
vector<int> prime;
void primes() 
{
    sieve.set();
    sieve[0] = sieve[1] = 0;
    int limit = sqrt(MAXN);
    for (int i = 2; i <= limit; i++) 
    {
        if (sieve[i]) 
        {
            for (int j = i * i; j <= MAXN; j += i) 
            {
                sieve[j] = 0;
            }
        }
    }
    for(int i=2;i<=MAXN;i++)
    {
        if(sieve[i]) prime.pb(i);
    }
}

mll prime_factor(ll n) 
{
    mll ret;
    for (ll i = 2; i * i <= n; i++) 
    {
        while (n % i == 0) 
        {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) ret[n]++;
    return ret;
}
void solve()
{
    int n;
    cin>>n;
    mll fct;
    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            fct[1]++;
            continue;
        }
        ll x=a[i];
        ll xx=sqrt(x);
        for(auto it:prime)
        {
            while(x%it==0)
            {
                fct[it]++;
                x/=it;
            }
            if(x==1 || it>=xx) break;
        }
        if(x!=1) fct[x]++;
        fct[1]++;
        
    }
    /* for(auto it:fct)
    {
        cout<<it.ff<<' '<<it.ss<<endl;
    } */
    for(auto it:fct)
    {
        if(it.ss%n)
        {
            yn(0);
            return;
        }
    }
    yn(1);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Test,TT = 0;
    primes();
    cin >> Test;
    while (TT++<Test)
    {
        //cout<<"Case "<<TT<<": ";
        solve();
    }
    return 0;
}