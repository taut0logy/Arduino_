#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\G_ABBC_or_BACB.cpp"
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    int a=0,ans=0;
    string ss=s;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='B')
        {
            v.push_back(a);
            a=0;
        }
        else a++;
    }
    v.push_back(a);
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++)
    {
        ans+=v[i];
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
        //cout<<"Case "<<TT<<": ";
        solve();
    }
    return 0;
}