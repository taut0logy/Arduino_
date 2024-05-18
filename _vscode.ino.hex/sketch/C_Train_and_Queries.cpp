#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Train_and_Queries.cpp"
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
void solve()
{
        cin.get();
        int n,k1;
        cin>>n>>k1;
        int ar[n];
        f(i,0,n,1) cin>>ar[i];
        while(k1--)
        {
            int a,b,l=0,r=0,f=0;
            cin>>a>>b;
            f(i,0,n,1)
            {
                if(ar[i]==a)
                {
                    f++;
                    break;
                }
            }
            f(i,0,n,1)
            {
                if(ar[i]==b)
                {
                    f++;
                    break;
                }
            }
            if(f<2) cout<<"NO"<<endl;
            else{
                    vi vl;
            vi vr;
            f(i,0,n,1)
            {
 
                if(ar[i]==a)
                {
                    vl.pb(i);
                }
                else if(ar[i]==b)
                {
                    vr.pb(i);
                }
            }
            //cout<<"vl"<<' ';
            //printv(vl);
            //cout<<"vr"<<' ';
            //printv(vr);
            sort(vl.bg,vl.en);
            sort(vr.bg,vr.en);
            if(vr.back()>vl[0]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            }
        }
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
        solve();
    }
    return 0;
}