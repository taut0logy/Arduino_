#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\hfhf.cpp"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define SIZE 1e6 + 2
#define endl "\n"

bool chk(vector<ll> a)
{
    for (ll i = 0; i < a.size() - 1; i++)
        if (a[i] != a[i + 1])
            return false;
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    if (chk(a))
    {
        cout << 0 << endl;
        return;
    }
    vector<vector<ll>> ans;
    vector<ll> prev = a;
    while (chk(a) == false)
    {
        ll mini = INT_MAX;
        ll ind = -1;
        for (ll i = 0; i < n; i++)
        {
            if (a[i] < mini)
            {
                mini = a[i];
                ind = i;
            }
        }
        bool ok = false;
        for (ll i = 0; i < n; i++)
        {
            if (a[i] != mini and a[i] > mini)
            {
                ll y = (a[i] / mini);
                if (a[i] % mini != 0)
                {
                    y++;
                }
                ans.push_back({i, ind});
                a[i] = y;
                ok = true;
            }
        }
        if (a == prev)
        {
            cout << -1 << endl;
            return;
        }
        prev = a;
    }
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it[0] + 1 << " " << it[1] + 1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}