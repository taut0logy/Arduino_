#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\D_Challenging_Valleys.cpp"
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
    int n,ind=-1;
    cin>>n;
    ll a[n],b[n],minn=10000000000;;
    f(i,0,n,1) 
    {
        cin>>a[i];
        if(a[i]<minn) minn=a[i];
    }
    if(n==1)
    {
        cout<<"YES"<<endl;
        return;
    }
    bool f=true;
    //cout<<minn<<endl;
    if(a[0]==minn)
    {
        f(i,0,n-1,1)
        {
            if(a[i]>a[i+1])
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    if(a[n-1]==minn)
    {
        fr(i,n-1,1,1)
        {
            if(a[i]>a[i-1])
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    f(i,0,n,1)
    {
        if(a[i]==minn)
        {
            ind=i;
            break;
        }
    }
    f(i,0,ind,1)
    {
        if(a[i]<a[i+1])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    f(i,ind,n-1,1)
    {
        if(a[i]>a[i+1])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    //cout<<ind<<endl;
    cout<<"YES"<<endl;

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
