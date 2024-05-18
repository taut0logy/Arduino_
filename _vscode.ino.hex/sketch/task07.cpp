#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\task07.cpp"
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ways;
vector<int> v;
int a[1005];
int weight[1005];
int dp[1005][1005];
int mx,val=0;
void knapsack(int n,int w)
{
    if(n==0 || w==0)
    {
        if(val==mx) ways.push_back(v);
        return ;
    }
    if(weight[n-1]<=w)
    {
        v.push_back(a[n-1]);
        val+=a[n-1];
        knapsack(n-1,w-weight[n-1]);
        v.pop_back();
        val-=a[n-1];
    }
    knapsack(n-1,w);
}

int knapsack2(int n,int w)
{
    if(n==0 || w==0)
    {
        return 0;
    }
    if(dp[n][w]!=-1)
    {
        return dp[n][w];
    }
    if(weight[n-1]<=w)
    {
        return dp[n][w]=max(a[n-1]+knapsack2(n-1,w-weight[n-1]),knapsack2(n-1,w));
    }
    else
    {
        return dp[n][w]=knapsack2(n-1,w);
    }
}

int main()
{
    int n,x;
    cin>>n>>x;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) cin>>weight[i]>>a[i];
    ways.clear();
    v.clear();
    val=0;
    mx=knapsack2(n,x);
    //cout<<mx<<endl;
    knapsack(n,x);
    for(auto i:ways)
    {
        for(auto j:i) cout<<j<<' ';
        cout<<endl;
    }

    return 0;
}

//6 6
//1 10
//2 20
//3 30
//4 40
//5 50
//6 60

