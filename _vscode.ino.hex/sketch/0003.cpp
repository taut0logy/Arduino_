#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\0003.cpp"
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
    int i,j,n,x;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        x=1;
        for(j=1;j<=i;j++)
        {
            cout<<x<<' ';
            x=x*(i-j)/j;
        }
        cout<<endl;
    }

    return 0;
}

