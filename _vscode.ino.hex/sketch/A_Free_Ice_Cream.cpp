#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Free_Ice_Cream.cpp"
#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b, x) for (int i = a; i < b; i += x)
#define fr(i, a, b, x) for (int i = a; i >= b; i -= x)
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
typedef set<string> sst;
typedef map<int, int> mii;
typedef map<long long, long long> mll;
typedef map<int, string> mis;
typedef map<string, int> msi;
typedef map<string, string> mss;
typedef map<char, int> mci;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<long long, long long> pll;

int main()
{
    int n, cnt = 0;
    char c;
    long long k = 0, x = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> c >> k;
        if (c == '+')
            x += k;
        else if (x - k >= 0)
        {
            x -= k;
        }
        else
        {
            cnt++;
        }
    }
    cout << x << " " << cnt << endl;
    return 0;
}