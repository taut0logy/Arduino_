#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Johny_English_and_Group_Formation.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll> m;
bool comp(ll a, ll b)
{
    if (m[a] == m[b])
        return a > b;
    return m[a] > m[b];
}
void solve()
{
    ll n, cnt = 0;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
        cnt = max(cnt, m[a[i]]);
    }
    cnt = min(n - cnt, n / 2);
    cnt += n - 2 * cnt;
    /* sort(a, a + n, comp);
    stack<ll> s;
    for (ll i = 0; i < n; i++)
    {
        if (s.empty() || s.top() == a[i])
        {
            s.push(a[i]);
            cnt++;
        }
        else s.pop();
    } */
    cout << cnt << endl;
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