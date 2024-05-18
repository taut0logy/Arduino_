#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Team.cpp"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll one, zero;
    cin >> zero >> one;
    if(one==zero+1)
    {
        cout<<"1";
        for (int i = 0; i < zero; i++)
            cout << "01";
    }
    else if (one == zero)
    {   
        for (int i = 0; i < zero; i++)
            cout << "01";
    }
    else if (one == zero - 1)
    {
        cout << "0";
        for (int i = 0; i < zero - 1; i++)
            cout << "10";
    }
    else if(one>zero+1 && one<=2*(zero+1))
    {
        while(one>zero)
        {
            cout<<"110";
            one-=2;
            zero--;
            if(!zero) break;
        }
        if(!zero)
        {
            if(!one) return;
            if(one==1) cout<<"1";
            else if(one==2) cout<<"11";
            else cout<<"-1";
            return;
        } else
        while(zero--)
        {
            cout<<"10";
            one--;
        }
        if(one) cout<<"1";
    }
    else cout<<"-1";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin >> t;
    int test = t;
    while (t--)
    {
        solve();
    }
    return 0;
}