#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Stand-up_Comedian.cpp"
#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b, x) for (long long i = a; i < b; i += x)
#define fr(i, a, b, x) for (long long i = a; i >= b; i -= x)
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
    //hacked
    ll ab,a,b,x;
    cin>>ab>>a>>b>>x;
    if(ab==0)
    {
        cout<<1<<endl;
        return;
    }
    if(ab+a+b+x==0)
    {
        cout<<0<<endl;
        return;
    }
    ll al=ab,bb=ab;
    ll ans=ab;
    while(a>0 || b>0 || x>0)
    {
        if(bb>0 && a>0)
        {
            ll y=min(bb,a);
            ans+=y;
            al+=y;
            bb-=y;
            a-=y;
        }
        else if(al>0 && b>0)
        {
            ll y=min(al,b);
            ans+=y;
            bb+=y;
            al-=y;
            b-=y;
        }
        else if(al>0  && bb>0 && x>0)
        {
            ll y=min(min(al,bb),x);
            al-=al;
            bb-=y;
            ans+=y;
            x-=y;
        }
        else
        {
            if(a!=0 || b!=0 || x!=0)
            {
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
}
void solve2()
{
    ll ab,a,b,x;
    cin>>ab>>a>>b>>x;
    ll ans2=ab+a+b+x;
    if(ab==0)
    {
        cout<<1<<endl;
        return;
    }
    if(ans2==0)
    {
        cout<<0<<endl;
        return;
    }
    ll ans=ab;
    ll y=min(a,b);
    ans+=2*y;
    a-=y;
    b-=y;
    a=min(ab,a);
    b=min(ab,b);
    ans+=a+b+min(x,min(ab-a,ab-b));
    ans=min(ans+1,ans2);
    cout<<ans<<endl;
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
        solve2();
    }
    return 0;
}