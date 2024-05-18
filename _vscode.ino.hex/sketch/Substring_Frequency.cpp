#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Substring_Frequency.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    string a,b;
    cin>>a>>b;
    ll n=a.size();
    ll m=b.size();
    vector<ll>lps(m);
    ll i=1,j=0;
    while(i<m)
    {
        if(b[i]==b[j])
        {
            lps[i]=j+1;
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    i=0,j=0;
    ll ans=0;
    while(i<n)
    {
        if(a[i]==b[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
        if(j==m)
        {
            ans++;
            j=lps[j-1];
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
