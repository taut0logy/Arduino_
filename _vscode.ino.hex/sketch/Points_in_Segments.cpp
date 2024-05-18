#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Points_in_Segments.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int ans = upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l);
        cout<<ans<<endl;
    }
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
        cout<<"Case "<<TT<<":\n";
        solve();
    }
    return 0;
}