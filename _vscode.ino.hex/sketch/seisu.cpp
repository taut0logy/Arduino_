#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\seisu.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<pair<ll,ll>>v;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    ll ans=0,x=0;
    for(int mask=0;mask<=30;mask++)
    {
        if()
    }
}