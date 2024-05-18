#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Matrix_Game.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n,m;
    cin>>n>>m;
    ll sum,ans=0;
    for(int i=0;i<n;i++)
    {
        sum=0;
        for(int j=0;j<m;j++)
        {
            ll v;
            cin>>v;
            sum+=v;
        }
        ans^=sum;
    }
    cout<<(ans?"Alice":"Bob")<<endl;
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