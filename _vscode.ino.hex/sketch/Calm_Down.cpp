#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Calm_Down.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    double R,n;
    cin>>R>>n;
    double theta = 2*acos(0.0)/n;
    double r = R*sin(theta)/(1+sin(theta));
    cout<<fixed<<setprecision(10)<<r<<endl;
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