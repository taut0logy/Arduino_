#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Lucky_Sum_of_Digits.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin>>n;
    ll x=0,y=0;
    while(n>=0)
    {
        if(n%7==0)
        {
            x=n/7;
            n=0;
            break;
        }
        y++;
        n-=4;
    }
    if(n)
    {
        cout<<-1<<endl;
        return;
    }
    while(y--) cout<<4;
    while(x--) cout<<7;
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
   // cin >> t;
    int test = t;
    while (t--)
    {
        solve();
    }
    return 0;
}