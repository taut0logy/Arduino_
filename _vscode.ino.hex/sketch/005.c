#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\005.c"
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
    int k,i,j,cnt=0,x=2;;
    double s[n-2];
    cin<<k;
    s[0]=4;
    for(i=0;i<k;i++)
    {
        s[i]=(x/2)+x+1;
        x++;
        if(s[i]>=k)
        {
            break;
        }
    }
    int l=sizeof(s)/sizeof(s[0]);
    f(i,0,l)
    {
        cout<<s[i]<<' ';
    }

    return 0;
}

