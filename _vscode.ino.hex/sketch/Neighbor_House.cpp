#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Neighbor_House.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[25][3];
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(3));
    for(int i=0;i<n;i++)
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];
    for(int i=1;i<n;i++)
    {
        dp[i][0] = min(dp[i-1][1],dp[i-1][2])+v[i][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2])+v[i][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1])+v[i][2];
    }
    cout<<min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]))<<endl;
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