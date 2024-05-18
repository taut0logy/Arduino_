#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\t.cpp"
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
        int n,k;
        cin>>n>>k;
        ll sum[n];
        sum[0]=k,sum[1]=k;
        f(i,2,n)
        {
            sum[i]=accumulate(sum,sum+i,0);
        }
        cout<<sum[n-1]<<endl;
        f(i,0,n)
        {
            cout<<sum[i]<<' ';
        }

    }
    return 0;
}


