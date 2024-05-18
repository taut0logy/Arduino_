#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Notepad.cpp"
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
    int n;
    cin>>n;
    string s,s1="";
    cin >> s;
    msi m;
    s1+=s[0];
    s1+=s[1];
    m[s1]++;
    bool f=false;
    f(i,1,n-1,1)
    {
        string str="";
        str+=s[i];
        str+=s[i+1];      
        if(m[str])
        {
            if((str==s1 && m[str]>1) || str!=s1)
            {
                f=true;
                break;
            }
        }
        m[str]++;
        s1=str;
    }
    yn(f);
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