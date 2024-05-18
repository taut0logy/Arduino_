#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\t2.cpp"
#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define pp pop_back
#define vsort(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define yn(flag) cout<<(flag?"YES":"NO")<<endl;
#define bg begin()
#define en end()
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef long long ll;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k,ans;
        cin>>n>>k;
        int l=n-2;
        vi v;
        v.pb(k);
        v.pb(k);
        while(l--)
        {
            int sum=accumulate(v.bg,v.en,0);
            v.pb(sum);
        }

        cout<<v[n-1]<<endl;
        for(auto x:v)
        {
            cout<<x<<' ';
        }
    }
    return 0;
}


