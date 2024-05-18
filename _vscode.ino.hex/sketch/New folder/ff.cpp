#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\New folder\\ff.cpp"
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
void solve()
{
    int n;
    cin>>n;
    string s[1000];
    string id;
    string time;
    string dob;
    string blood;
    mss m,tb,tbir;
    msi bm,mby;
    vs v={"A+","A-","AB+","AB-","B+","B-","O+","O-"};
    while(n--)
    {
        cin>>time>>id>>dob>>blood;
        string byear=dob.substr(6,4);
        if(m[id].size()==0)
        {
            m[id]=time;
            bm[blood]++;
            mby[byear]++;
            tb[time]=blood;
            tbir[time]=byear;
            continue;
        }
        char*c1=&m[id][0];
        char*c2=&time[0];
        if(strcmp(c1,c2)<0)
        {
            bm[blood]++;
            mby[byear]++;
            mby[tbir[m[id]]]--;
            bm[tb[m[id]]]--;
            tb[time]=blood;
            tbir[time]=byear;
            m[id]=time;
        }
    }
    for(auto x:v)
    {
        cout<<x<<' '<<bm[x]<<endl;
    }
    for(auto x:mby)
    {
        cout<<x.first<<' '<<x.second<<endl;
    }
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