#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Matching_Numbers.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin>>n;
    if(n%2==0)
    {
        cout<<"No"<<endl;
        return;
    }
    int i=1,j=2*n;
    cout<<"Yes"<<endl;
    while(i<j)
    {
        cout<<i<<" "<<j<<endl;
        i++;
        j--;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}