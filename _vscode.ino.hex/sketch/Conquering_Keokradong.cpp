#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Conquering_Keokradong.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(int dis[],int n,int k,int mid)
{
    int cnt=0,cur=0;
    for(int i=0;i<=n;i++)
    {
        if(cur+dis[i]>mid)
        {
            cnt++;
            cur=dis[i];
        }
        else cur+=dis[i];
    }
    return cnt<=k;
}
void solve()
{
    int n,k,l=0,r=0;
    cin>>n>>k;
    int dis[n+1];
    for(int i=0;i<=n;i++)
    {
        cin>>dis[i];
        l=max(l,dis[i]);
        r+=dis[i];
    }
    int ans=l;
    while (l<r)
    {
        int mid=(l+r)/2;
        if(check(dis,n,k,mid))
        {
            ans=mid;
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    int cur=0;
    for(int i=0;i<=n;i++)
    {
        cur+=dis[i];
        if(cur>ans || n-i+1==k)
        {
            cout<<cur-dis[i]<<endl;
            cur=dis[i];
            k--;
        }
    }
    cout<<cur<<endl;

    
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
        cout<<"Case "<<TT<<": ";
        solve();
    }
    return 0;
}