#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\AN_-_LCS.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    string lcs;
    int n=s1.length();
    int m=s2.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0) dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            lcs.push_back(s1[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    reverse(lcs.begin(),lcs.end());
    cout<<lcs<<endl;
    return 0;
}