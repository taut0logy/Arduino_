#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Juice_in_the_Glass.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    double r1,r2,h,p;
    cin>>r1>>r2>>h>>p;
    double r = r2+(r1-r2)*(p/h);
    double ans = 2*(acos(0.0)*(r*r+r2*r2+r*r2)*p)/3;
    cout<<fixed<<setprecision(10)<<ans<<endl;
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