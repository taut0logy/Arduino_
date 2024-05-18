#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Soldier_and_Cards.cpp"
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int k1;
    cin>>k1;
    queue<int> a;
    for(int i=0;i<k1;i++)
    {
        int x;
        cin>>x;
        a.push(x);
    }
    int k2;
    cin>>k2;
    queue<int> b;
    for(int i=0;i<k2;i++)
    {
        int x;
        cin>>x;
        b.push(x);
    }
    int ans=0;
    int cnt=100000;
    while(cnt--)
    {
        int x=a.front();
        a.pop();
        int y=b.front();
        b.pop();
        if(x>y)
        {
            a.push(y);
            a.push(x);
        }
        else
        {
            b.push(x);
            b.push(y);
        }
        ans++;
        if(a.empty())
        {
            cout<<ans<<' '<<2<<endl;
            return;
        }
        if(b.empty())
        {
            cout<<ans<<' '<<1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}