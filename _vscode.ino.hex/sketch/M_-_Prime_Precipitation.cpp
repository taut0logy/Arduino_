#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\M_-_Prime_Precipitation.cpp"
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
const long long M=1e9+7;
const int MAXN = 4000000;
bitset<MAXN + 1> sieve;
vl prime;
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
    for (int i = 2; i <= MAXN; i++) 
    {
        if (sieve[i]) 
        {
            prime.pb(i);
        }
    }
}
ll perc(ll n)
{
    int ans=0;
    for(auto i:prime)
    {
        if(!n || i>n)
        break;
        if(n%i==0)
        {
            while(n>0 && n%i==0)
            {
                n/=i;
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    primes();
    ll h;
    cin>>h;
    vl v(h+1,-1);
    ll ans=0;
    fr(i,h,1,1)
    {
            ll j=i;
            ll cnt=0;
            while(j>=1)
            {
                ll u=perc(j);
                j-=u;
                cout<<j<<endl;
                ans++;
            }
    }
    cout<<ans<<endl;
    return 0;
}