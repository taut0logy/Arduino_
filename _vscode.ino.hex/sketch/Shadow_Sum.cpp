#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Shadow_Sum.cpp"
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    vector<int> v;
    map<int, int> m;
    int n,sum=0;
    cin >> n;
    while(n--)
    {
        int x;
        cin>>x;
        if(m[x]) continue;
        else if(m[-1*x])
        {
            sum+=2*x;
            m[-1*x]--;
            m[x]++;
        }
        else
        {
            sum+=x;
            m[x]++;
        }
    }
    cout<<sum<<endl;
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