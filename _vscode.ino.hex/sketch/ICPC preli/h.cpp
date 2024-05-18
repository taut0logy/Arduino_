#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\ICPC preli\\h.cpp"
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define pp pop_back()
#define ppf pop_front()
#define rev(v) reverse(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define yn(flag) cout << (flag ? "YES" : "NO") << endl;
#define yout cout << "YES" << endl
#define nout cout << "NO" << endl
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define fr front()
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
typedef set<char> sc;
typedef set<string> sst;
typedef map<int, int> mii;
typedef map<long long, long long> mll;
typedef map<int, string> mis;
typedef map<string, int> msi;
typedef map<string, string> mss;
typedef map<char, int> mci;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<char, char> pcc;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<string, long long> psl;
typedef pair<long long, long long> pll;
const long long M=1e9+7;
const long long INF=1e18;
const long long N=1e5+5;
const double pi=acos(-1);
const double eps=1e-9;
const long long mod=998244353;
vector<vector<int>> buckets;
    vector<int> v;
    int which[125];
bool isPartitionPossible(ll a[],int n,int k,ll bucketSum,int sum,int bucket,int taken[])
{
    if(bucket==k){
        return true;
    }
    if(sum==bucketSum){
        buckets.push_back(v);
        return isPartitionPossible(a,n,k,bucketSum,0,bucket+1,taken);

    }
    if(sum>bucketSum)
        return false;

    for (int i = 0; i < n; i++)
    {
        if(!taken[i])
        {
            taken[i]=1;
            v.push_back(a[i]);
            if(isPartitionPossible(a,n,k,bucketSum,sum+a[i],bucket,taken))
                return true;
            taken[i]=0;
            v.pop_back();
        }
    }
    return false;
}

void solve()
{

    int n;
    cin>>n;
    ll a[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll sum=0;
    int taken[n]={0};
    bool flag=isPartitionPossible(a,n,3,sum,0,0,taken);
    vector<vector<int>> buckets;
    vector<int> v;
    int which[n];
    for (int i = 0; i < n; i++)
    {
        sum+=a[i];
        if(!sum)
        {
            cout<<"1"<<endl;
            continue;
        }
        if(sum%3)
        {
            cout<<"0"<<endl;
            continue;
        }
        ll bucketSum=sum/3;
        int taken[n]={0};
        if(isPartitionPossible(a,i+1,3,bucketSum,0,0,taken))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Test,TT = 0;
    cin >> Test;
    while (TT++<Test)
    {
        cout<<"Case "<<TT<<": "<<endl;
        solve();
    }
    return 0;
}