#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\AM_-_Vacation.cpp"
#include<bits/stdc++.h>
using namespace std;
int dp[3][100005];
int main()
{
    int n;
    cin>>n;
    int a[n][3];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    dp[0][0]=a[0][0];
    dp[1][0]=a[0][1];
    dp[2][0]=a[0][2];
    for(int i=1;i<n;i++)
    {
        dp[0][i]=a[i][0]+max(dp[1][i-1],dp[2][i-1]);
        dp[1][i]=a[i][1]+max(dp[0][i-1],dp[2][i-1]);
        dp[2][i]=a[i][2]+max(dp[0][i-1],dp[1][i-1]);
    }
    cout<<max(dp[0][n-1],max(dp[1][n-1],dp[2][n-1]))<<endl;
    return 0;
}