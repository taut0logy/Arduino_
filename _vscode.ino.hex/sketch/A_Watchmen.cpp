#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Watchmen.cpp"
#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b,x) for(int i=a;i<b;i+=x)
#define fr(i,a,b,x) for(int i=a;i>=b;i-=x)
#define pb push_back
#define pp pop_back
#define pf pop_front
#define vsort(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define yn(flag) cout<<(flag?"YES":"NO")<<endl;
#define bg begin()
#define en end()
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef long long ll;
typedef map<int,int> mii;
typedef map<int,string> mis;
typedef map<string,int> msi;
typedef map<char,int> mci;

int main()
{

        int n,cntx=0,cnty=0,cntd=0;
        cin>>n;
        ll x[n],y[n];
        f(i,0,n,1)
        {
            cin>>x[i]>>y[i];
        }
        map<ll,ll> xx;
        map<ll,ll> yy;
        map<pair<ll,ll>,ll> dup;
        f(i,0,n,1)
        {
            xx[x[i]]++;
            yy[y[i]]++;
            pair<ll,ll> p;
            p.first=x[i],p.second=y[i];
            dup[p]++;
        }
        for(auto m:xx) cntx+=.5*m.second*(m.second-1);
        for(auto m:yy) cnty+=.5*m.second*(m.second-1);
        for(auto m:dup) cntd+=.5*m.second*(m.second-1);
        ll ans=cntx+cnty-cntd;
        cout<<ans;

    return 0;
}