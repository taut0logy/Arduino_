#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Quick_Sort.cpp"
#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b, x) for (long long i = a; i < b; i += x)

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, cnt = 0, k, y = 1;
        cin >> n >> k;
        ll a[n];
        f(i, 0, n, 1)
        {
            cin >> a[i];
            if (a[i] == y)
            {
                cnt++;
                y++;
            }
        }
        ll x = ceil((n - cnt) / (k * 1.0));
        cout << x << endl;
    }
    return 0;
}