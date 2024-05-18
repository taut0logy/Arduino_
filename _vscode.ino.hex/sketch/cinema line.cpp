#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\cinema line.cpp"
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
typedef vector<long long> vl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef long long ll;
typedef map<int,int> mii;
typedef map<long long,long long> mll;
typedef map<int,string> mis;
typedef map<string,int> msi;
typedef map<char,int> mci;
typedef pair<int,int> pii;
typedef pair<string,int> psi;
typedef pair<long long,long long>pll;
int main()
{
    int n,flag=0;
    cin>>n;
    int a[n];
    int change[3];
    f(i,0,3,1) change[i]=0;
    f(i,0,n,1) cin>>a[i];
    f(i,0,n,1)
    {
        if(a[i]==25) change[0]++;
        else if(a[i]==50)
        {
            change[1]++;
            change[0]--;
            if(change[0]<0)
            {
                flag++;
                break;
            }
        }
        else if(a[i]==100)
        {
            change[2]++;
            if(change[0]>0 && change[1]>0)
            {
                change[0]--;
                change[1]--;
            }
            else if(change[0]>2 && change[1]==0)
            {
                change[0]-=3;
            }
            else
            {
                flag++;
                break;
            }
        }
    }
    if(flag==0) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
    return 0;
}
