#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Save_the_Magazines.cpp"
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
        int n,cnt=0;
        cin>>n;
        string s;
        cin>>s;
        int a[n];
        ll sum=0;
        f(i,0,n,1)
        {
            cin>>a[i];
            sum+=a[i];
        }
        f(i,0,n,1)
        {
            if(s[i]=='0') sum-=a[i];
            if(s[i]=='1') cnt++;
        }
        if(cnt==n) cout<<sum<<endl;
        if(sum==0) cout<<0<<endl;
        else if(n==1)
        {
            if(s[0]=='1') cout<<a[0]<<endl;
            else cout<<0<<' '<<endl;
        }
        else
        {
            f(i,0,n,1)
            {
                int j;
                /* if(s[i]=='1' && s[i-1]=='0' && a[i-1]>a[i])
                {
                    sum+=a[i-1]-a[i];
                    s[i]='0';
                    s[i-1]='1';
                }  */
                if(s[i]=='1')
                {
                    fr(k,i-1,0,1)
                    {
                        if(k==0 && a[k]=='1')
                        {
                            j=-1;
                        }
                        if(s[k]=='0')
                        {

                            j=k;
                            break;
                        }
                    }
                }
                if(j<0) break;
                if(a[i]<a[j])
                {
                    sum+=a[j]-a[i];
                    s[i]='0';
                    s[j]='1';
                }
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
