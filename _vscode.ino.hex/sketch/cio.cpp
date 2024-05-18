#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\cio.cpp"
#include <bits/stdc++.h>
using namespace std;
int main()
{

    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> S(n);
    set<string> st;
    for (int i = 0; i < n; ++i)
        cin >> S[i];
    for (int i = 0; i < m; ++i)
    {
        string t;
        cin >> t;
        st.insert(t);
    }
    sort(S.begin(), S.end());
    int tot = n - 1;
    vector<int> a(n - 1);
    for (int i = 0; i < S.size(); ++i)
        tot += S[i].size();
    function<void(int, int, string)> dfs = [&](int cur, int v, string q)
    {
        if (cur == n - 1)
        {
            q += S[cur];
            if (q.size() >= 3 && !st.count(q))
            {
                cout << q << "\n";
                exit(0);
            }
        }
        else
        {
            q += S[cur] + "_";
            for (int i = 0; i <= v; ++i)
            {
                dfs(cur + 1, v - i, q);
                q += "_";
            }
        }
    };
    do
    {
        dfs(0, 16 - tot, "");
    } while (next_permutation(S.begin(), S.end()));
    cout << -1;
    return 0;
}