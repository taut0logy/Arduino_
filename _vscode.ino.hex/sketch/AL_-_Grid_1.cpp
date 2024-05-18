#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\AL_-_Grid_1.cpp"
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod = 1e9 + 7;
long long dp[1005][1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h,w;
    cin>>h>>w;
    vector<string> s(h);
    for(int i=0;i<h;i++)
    {
        cin>>s[i];
    }
    dp[0][0]=1;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(s[i][j]=='#') continue;
            if(i>0) dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            if(j>0) dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
        }
    }
    cout<<dp[h-1][w-1]<<endl;
    return 0;
}