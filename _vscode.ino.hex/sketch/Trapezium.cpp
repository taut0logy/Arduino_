#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Trapezium.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    //if(c>a) swap(a,c);
    double x=1.0*(b*b-d*d+(a-c)*(a-c))/(2*(a-c));
    double y=sqrt(b*b-x*x);
    double ans=0.5*(a+c)*y;
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