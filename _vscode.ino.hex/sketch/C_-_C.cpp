#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_-_C.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int longest_common_substring(string a,string b)
{
    int n=a.length();
    int m=b.length();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        string a=s.substr(x);
        string b=s.substr(y);
        int ans=longest_common_substring(a,b);
        cout<<ans<<endl;
    }
    return 0;
}