#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Coins.cpp"
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n,k;
    cin>>n>>k; 
    if(n%2==0 || n==k)
    {
        cout<<"YES"<<endl;
        return;
    }
    if(n-k>0 && (n-k)%2==0)
    {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    int test = t;
    while (t--)
    {
        solve();
    }
    return 0;
}