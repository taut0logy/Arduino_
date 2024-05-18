#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Olympics.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    string s;
    getline(cin>>ws,s);
    double a,b;
    stringstream ss(s);
    char c;
    ss>>a>>c>>b;
    //cout<<a<<" "<<b<<endl;
    double r = sqrt(a*a+b*b)/2;
    double theta = acos((r*r*2-b*b)/(2*r*r));
    double arc = r*theta;
    double x=400.0/(2*(a+arc));
    double l=x*a,w=x*b;
    cout<<fixed<<setprecision(10)<<l<<" "<<w<<endl;
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