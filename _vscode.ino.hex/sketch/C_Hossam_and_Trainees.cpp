#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Hossam_and_Trainees.cpp"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1000000;
bitset<MAXN + 1> sieve;
vector<ll> prime;
void primes()
{
    sieve.set();
    sieve[0] = sieve[1] = 0;
    int limit = sqrt(MAXN);
    for (ll i = 2; i <= limit; i++)
    {
        if (sieve[i])
        {
            for (ll j = i * i; j <= MAXN; j += i)
            {
                sieve[j] = 0;
            }
        }
    }
    for (ll i = 2; i <= MAXN; i++)
    {
        if (sieve[i])
        {
            prime.push_back(i);
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    map<ll, ll> mp;
    bool f = false;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (f)
            continue;
        for (ll j = 0; prime[j] * prime[j] <= x; j++)
        {
            if (x % prime[j] == 0)
            {
                while (x % prime[j] == 0)
                    x /= prime[j];
                mp[prime[j]]++;
                if (mp[prime[j]] > 1)
                {
                    f = true;
                    break;
                }
            }
        }
        if (f)
            continue;
        if (x != 1)
        {
            mp[x]++;
            if (mp[x] > 1)
                f = true;
        }
    }
    if (f)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    primes();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}