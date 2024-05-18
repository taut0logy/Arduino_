#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\E_-_E.cpp"
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
bool work(string a,char sign,string b,string c)
{
    ll x=0;
    f(i,0,a.size(),1)
    {
        x=x*10+(a[i]-'0');
    }
    int y=0;
    f(i,0,b.size(),1)
    {
        y=y*10+(b[i]-'0');
    }
    int z=0;
    f(i,0,c.size(),1)
    {
        z=z*10+(c[i]-'0');
    }

    if(sign=='+')
    {
        return x+y==z;
    }
    else
    {
        return x*y==z;
    }
}
void solve()
{
    string a,b,c,eql;
    char sign;
    cin>>a>>sign>>b>>eql>>c;
    f(i,1,a.size(),1)
    {
        string x1=a.substr(0,i);
        string x2=a.substr(i);
        f(j,1,b.size(),1)
        {
            string y1=b.substr(0,j);
            string y2=b.substr(j);
            string ans1=y1+x2;
            string ans2=x1+y2;
            if(work(ans1,sign,ans2,c))
            {
                cout<<ans1<<' '<<sign<<' '<<ans2<<" = "<<c<<endl;
                return;
            }
        }
    }
    f(i,1,a.size(),1)
    {
        string x1=a.substr(0,i);
        string x2=a.substr(i);
        f(j,1,c.size(),1)
        {
            string y1=c.substr(0,j);
            string y2=c.substr(j);
            string ans1=y1+x2;
            string ans2=x1+y2;
            if(work(ans1,sign,b,ans2))
            {
                cout<<ans1<<' '<<sign<<' '<<b<<" = "<<ans2<<endl;
                return;
            }
        }
    }
    f(i,1,b.size(),1)
    {
        string x1=b.substr(0,i);
        string x2=b.substr(i);
        f(j,1,c.size(),1)
        {
            string y1=c.substr(0,j);
            string y2=c.substr(j);
            string ans1=y1+x2;
            string ans2=x1+y2;
            if(work(a,sign,ans1,ans2))
            {
                cout<<a<<' '<<sign<<' '<<ans1<<" = "<<ans2<<endl;
                return;
            }
        }
    }
    cout<<"No equations work!"<<endl;
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