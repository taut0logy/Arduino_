#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\dp001.cpp"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long

void sol()
{
    int n, k;
    cin >> n >> k;
    map<int, int> m, ans;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;

        m[a]++;
        m[b]++;
    }

    for (auto val : m)
    {
        if (val.second == 1)
            continue;
        ans[val.second]++;
    }

    int x = 0, y = 0;
    for (auto val : ans)
    {
        if (val.second == 1)
        {
            x = val.first;
        }
        else
            y = val.first;
    }

    if (y == 0 || x == 0)
    {
        cout << x + y <<' '<< x + y - 1 << endl;
    }
    else
    {
        cout << x <<' '<< y - 1 << endl;
    }

    // for(auto val:ans){
    // cout<<val.first<<” “<<val.second<<endl;
    // }
    // cout<<endl;

    return;
}

signed main()
{

    int t;
    cin >> t;

    while (t--)
    {
        sol();
    }

    return 0;
}