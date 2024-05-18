#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\hii.cpp"
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
int countSubstring(const string &str, const string &sub)
{
    if (sub.length() == 0)
        return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != string::npos;
         offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}
void solve()
{

    string s;
    cin >> s;
    int n = s.size(), cnt = 0;
    int one = 0;
    int two = 0;
    f(i,1,n,1)
    {
        if(s[i-1]=='0' && s[i]=='1') one++;
        if(s[i-1]=='1' && s[i]=='0') two++;
    }
    int x, y;
    if (s[0] == '0')
    {
        x = one;
        y = two;
        if (s[1] == '0')
        {
            two++;
        }
        else if (s[1] == '1')
        {
            one--;
        }
        if (x == y)
            cnt++;
        one = x;
        two = y;
    }
    else
    {
        x = one;
        y = two;
        if (s[1] == '0')
        {
            two--;
        }
        else if (s[1] == '1')
        {
            one++;
        }
        if (x == y)
            cnt++;
        one = x;
        two = y;
    }
    if (s[n - 1] == '0')
    {
        x = one;
        y = two;
        if (s[n - 2] == '0')
        {
            one++;
        }
        else if (s[n - 2] == '1')
        {
            two--;
        }
        if (x == y)
            cnt++;
        one = x;
        two = y;
    }
    else
    {
        x = one;
        y = two;
        if (s[n - 2] == '0')
        {
            one--;
        }
        else if (s[n - 2] == '1')
        {
            two++;
        }
        if (x == y)
            cnt++;
        one = x;
        two = y;
    }
    f(i, 1, n - 1, 1)
    {
        if (s[i] == '0')
        {
            x = one;
            y = two;
            if (s[i + 1] == '0')
            {
                two++;
            }
            else if (s[i + 1] == '1')
            {
                one--;
            }
            if (s[i - 1] == '0')
            {
                one++;
            }
            else if (s[i - 1] == '1')
            {
                two--;
            }
            if (x == y)
                cnt++;
            one = x;
            two = y;
        }
        else
        {
            x = one;
            y = two;
            if (s[i + 1] == '0')
            {
                two--;
            }
            else if (s[i + 1] == '1')
            {
                one++;
            }
            if (s[i - 1] == '0')
            {
                one--;
            }
            else if (s[i - 1] == '1')
            {
                two++;
            }
            if (x == y)
                cnt++;
            one = x;
            two = y;
        }
    }
    // cout << one << ' ' << two << endl;
    cout << cnt << endl;
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