#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\D_Two-Colored_Dominoes.cpp"
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
void solve()
{
    int n,m;
    cin>>n>>m;
    vs v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    string c="WB";
    int cur=0;
    for(int j=0;j<m;j++)
    {
        int l=0;
        for(int i=0;i<n;i++)
        {
            if(v[i][j]=='L')
            {
                v[i][j]=c[cur];
                v[i][j+1]=c[1-cur];
                cur=1-cur;
                l++;
            }
        }
        if(l&1)
        {
            cout<<-1<<endl;
            return;
        }
    }
    for(int i=0;i<n;i++)
    {
        int u=0;
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='U')
            {
                v[i][j]=c[cur];
                v[i+1][j]=c[1-cur];
                cur=1-cur;
                u++;
            }     
        }
        if(u&1)
            {
                cout<<-1<<endl;
                return;
            }   
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<endl;
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Test,TT = 0;
    cin >> Test;
    while (TT++<Test)
    {
        //cout<<"Case "<<TT<<": ";
        solve();
    }
    return 0;
}