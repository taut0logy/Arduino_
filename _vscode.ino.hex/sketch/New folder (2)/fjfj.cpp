#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\New folder (2)\\fjfj.cpp"
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    string a = "SELISE";
    string b = "SELISE Digital Platforms";
    vsort(a);
    vsort(b);
    int test = t;
    for (int i = 1; i <= t; i++)
    {

        string s;
        getline(cin >> ws, s);
        /* f(i,0,sz(s),1)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                s[i]+=32;;
            }
        } */
        // cout<<s<<endl;
        sort(s.begin(), s.end());
        cout << "Case " << i << ": ";
        if (s.find(a) != string::npos)
        {
            if (s.find(b) != string::npos)
            {
                cout << "BOTH" << endl;
            }
            else
            {
                cout << "SELISE" << endl;
            }
        }
        else
        {
            if (s.find(b) != string::npos)
            {
                cout << "SELISE Digital Platforns" << endl;
            }
            else
            {
                cout << "NONE" << endl;
            }
        }
    }
    return 0;
}