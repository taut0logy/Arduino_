#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\G_-_G.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int hash[100005],d[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    d[0]=1;
    for(int i=1;i<=s.length();i++)
    {
        d[i]=d[i-1]*31;
        d[i]%=1000000007;
    }
    //map<pair<int,int>,int> mp;
    int dp[s.length()][26]={0};
    int q;
    cin>>q;
    for(int i=0;i<s.length();i++)
    {
        for(int j=0;j<26;j++)
        {
            if(i==0) dp[i][j]=0;
            else dp[i][j]=dp[i-1][j];
        }
        dp[i][s[i]-'a']++;
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        /* if(mp[{x,y}])
        {
            cout<<mp[{x,y}]<<endl;
            continue;
        } */
        int ans=0;
        x--;
        y--;
        if(x>0)
        {
            for(int i=0;i<26;i++)
            {
                if(dp[y][i]-dp[x-1][i]>0) ans++;
            }
        }
        else
        {
            for(int i=0;i<26;i++)
            {
                if(dp[y][i]>0) ans++;
            }
        }
        //for(;y<s.length() && s[x]==s[y];x++,y++) ans++;
        //mp[{x,y}]=ans;
        cout<<ans<<endl;
    }
}