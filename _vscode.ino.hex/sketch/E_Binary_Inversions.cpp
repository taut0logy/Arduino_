#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\E_Binary_Inversions.cpp"
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
    int n;
    ll cnt=0,cnt2=0,cnt3=0,x=0,y=0,z=0;
    cin>>n;
    bool f=true;
    int a[n],b[n],c[n];
    f(i,0,n,1)
    {
        cin>>a[i];
        b[i]=a[i];
        c[i]=a[i];
    }
    if(n==1)
    {
        cout<<0<<endl;
        return;
    }
    //if(a[0]==0) a[0]=1;
    //else
    f(i,0,n,1)
    {
        if(a[i]==0)
        {
            a[i]=1;
            break;
        }
    }
    fr(i,n-1,0,1)
    {
        if(b[i]==1)
        {
            b[i]=0;
            break;
        }
    }
    f(i,0,n,1)
    {
        if(a[i]==0)
        {
            cnt+=x;
        }
        else
        {
            x++;
        }
        if(b[i]==0)
        {
            cnt2+=y;
        }
        else
        {
            y++;
        }
        if(c[i]==0)
        {
            cnt3+=z;
        }
        else
        {
            z++;
        }
    }
    //cout<<cnt<<' '<<cnt2<<endl;
    cout<<max(cnt3,max(cnt,cnt2))<<endl;
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