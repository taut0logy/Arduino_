#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Monkey_Banana_Problem.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1005][1005];
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(2*n-1,vector<int>(n));
    for(int i=0;i<2*n-1;i++)
    {
        if(i<n)
        {
            for(int j=0;j<=i;j++)
                cin>>v[i][j];
        }
        else
        {
            for(int j=0;j<2*n-1-i;j++)
                cin>>v[i][j];
        }
    }
    dp[0][0] = v[0][0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0)
                dp[i][j] = dp[i-1][j]+v[i][j];
            else if(j==i)
                dp[i][j] = dp[i-1][j-1]+v[i][j];
            else
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+v[i][j];
        }
    }
    for(int i=n;i<2*n-1;i++)
    {
        for(int j=0;j<2*n-1-i;j++)
        {
            dp[i][j] = max(dp[i-1][j],dp[i-1][j+1])+v[i][j];
        }
    }
    cout<<dp[2*n-2][0]<<endl;
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