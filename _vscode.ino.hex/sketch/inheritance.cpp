#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\inheritance.cpp"
// create a function to find the longest subsrtings between two strings
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    int maxlen=0;
    int end=0;
    int dp[n+1][m+1]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
           if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            if(dp[i][j]>maxlen)
            {
                maxlen=dp[i][j];
                end=i-1;
            }
            /* else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            } */
        }
    }
    cout<<s1.substr(end-maxlen+1,maxlen)<<endl;
    cout<<maxlen<<endl;
    return 0;
}

/* #include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int dp[n];
    dp[0]=a[0];
    dp[1]=max(a[0],a[1]);
    for(int i=2;i<n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+a[i]);
    }
    cout<<dp[n-1]<<endl;
    return 0;
} */

/* This code is a dynamic programming solution to the maximum sum subarray problem.
It takes in an array of integers, n, and stores them in the array a[].
It then creates an array dp[] which stores the maximum sum subarray ending at each index.
The for loop starting at line 11 iterates through
each element of the array and updates dp[i] to be the maximum of either dp[i-1] or dp[i-2] + a[i].
Finally, it prints out the last element of dp[] which is the maximum sum subarray of a[]. */