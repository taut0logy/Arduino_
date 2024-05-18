#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\sort2d.cpp"
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end(), compare);
        for (auto it : v)
        {
            cout << it.first << ' ' << it.second << endl;
        }
    }
    return 0;
}
