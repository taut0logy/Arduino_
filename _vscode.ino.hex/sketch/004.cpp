#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\004.cpp"
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
        long long n,k,ans;
        cin>>n>>k;
        if(n<=2)
        {
            ans=k;
        }
        else
        {
            ans=k*pow(2,n-2);
        }
        cout<<ans<<endl;
    }
    return 0;
}

