#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\P_-_Partitioning_Game.cpp"
#include<bits/stdc++.h>
using namespace std;
int dp[10005];
bool ck[10005];
int grundy(int n)
{
    if(n==1) return 0;
    if(n==2) return 0;
    if(dp[n]!=-1) return dp[n];
    memset(ck,false,sizeof(ck));
    int m=n/2;
    if(n%2==0) m--;
    for(int i=1;i<=m;i++)
    {
        int x=grundy(i);
        int y=grundy(n-i);
        ck[x^y]=true;
    }
    int ans=0;
    for(int i=0;i<=10000;i++)
    {
        if(!ck[i])
        {
            ans=i;
            break;
        }
    }
    return dp[n]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=10000;i++) grundy(i);
    int T;
    cin>>T;
    int cs=0;
    while(cs++<T)
    {
        int n,ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            ans^=grundy(x);
        }
        if(ans) cout<<"Case "<<cs<<": Alice"<<endl;
        else cout<<"Case "<<cs<<": Bob"<<endl;
    }
    return 0;
}