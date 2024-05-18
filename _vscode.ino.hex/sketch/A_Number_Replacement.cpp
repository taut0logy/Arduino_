#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Number_Replacement.cpp"
#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b,x) for(int i=a;i<b;i+=x)
#define fr(i,a,b,x) for(int i=a;i>=b;i-=x)
#define ff(x,m) for(auto x:m)
#define pb push_back
#define pf push_front
#define pp pop_back()
#define ppf pop_front()
#define vsort(v) sort(v.begin(),v.end())
#define rsort(v) sort(v.begin(),v.end(),greater<>())
#define rev(v) reverse(v.begin(),v.end())
#define yn(flag) cout<<(flag?"YES":"NO")<<endl;
#define yout cout<<"YES"<<endl;
#define nout cout<<"NO"<<endl;
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
typedef map<int,int> mii;
typedef map<long long,long long> mll;
typedef map<int,string> mis;
typedef map<string,int> msi;
typedef map<string,string> mss;
typedef map<char,int> mci;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef pair<string,int> psi;
typedef pair<long long,long long>pll;
void printv(vector<auto> v)
{
    for(auto x: v) cout<<x<<' ';
    cout<<endl;
}
ll gcd(ll a, ll b)
{
    ll x=min(a,b);
    while(x>0)
    {
        if(a%x==0 && b%x==0) break;
        x--;
    }
    return x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    int test=t;
    while(t--)
    {
        int n;
        cin>>n;
        mii m;
        int a[n];
        f(i,0,n,1) 
        {
            cin>>a[i];
        }
        string s;
        cin>>s;
        si sa(a,a+n);
        set<char> ss(s.bg,s.en);
        if(s.size()!=n) cout<<"NO"<<endl;
        else
        {
            mci mc;
            mci mch;
            for(char i='a';i<='z';i++ ) mch[i]=-1;
            string st="";
            f(i,0,n,1)
            {
                
                if(mch[s[i]]!=-1) 
                {
                    st+=s[mch[s[i]]];
                    if(m[a[i]]==0)
                    {
                        mch[s[i]]=i;
                        m[a[i]]++;
                    }
                    
                }
                else
                {
                    st+=s[i];
                    if(m[a[i]]==0)
                    {
                        mch[s[i]]=i;
                        m[a[i]]++;
                    }
                }
                /* else if( mc[s[i]]==-1 || m[a[i]]==-1)
                {
                    st+=s[i];
                    m[a[i]]=i;
                    mc[s[i]]=i;
                } */
            }
            yn(st==s);
            cout<<st<<endl;
        }
    }
    return 0;
}