#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Brush_II.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n,w;
    cin>>n>>w;
    int x[n],y[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
    sort(y,y+n);
    int ans=1;
    int last=y[0];
    for(int i=1;i<n;i++)
    {
        if(y[i]-last>w)
        {
            ans++;
            last=y[i];
        }
    }
    cout<<ans<<endl;
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