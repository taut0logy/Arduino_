#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Table_Decorations.cpp"
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    ll ans;
    if(a[2]/2>=a[0]+a[1]) ans=a[0]+a[1];
    else ans=(a[0]+a[1]+a[2])/3;
    cout<<ans<<endl;
    return 0;
}