#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\dp_005.cpp"
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100000007;
int n, k;
int coins[1005], counts[1005], dp[1005][105];

int ways(int val, int idx) 
{
    if(val == 0) return 1;
    if(val < 0 || idx == n) return 0;
    if(dp[val][idx] != -1) return dp[val][idx];
    int ans = 0;
    for(int i = 0; i <= counts[idx]; i++)
    {
        ans = (ans+ways(val - coins[idx] * i, idx + 1))%N;
    }
    return dp[val][idx] = ans;
}

signed main()
{
    int cs=0;
    int t;
    cin>>t;
    while(t>cs++)
    {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> coins[i];
    for(int i = 0; i < n; i++) cin >> counts[i];
    memset(dp, -1, sizeof(dp));
    cout << "Case " << cs << ": " << ways(k, 0)%N << endl;
    }
    return 0;
}
