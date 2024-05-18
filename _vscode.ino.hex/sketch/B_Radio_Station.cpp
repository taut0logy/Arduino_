#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Radio_Station.cpp"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n, m;
    cin >> n >> m;
    map<string, string> mp;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        mp[b] = a;
    }
    for (int i = 0; i < m; i++)
    {
        string a, b;
        cin >> a >> b;
        b.pop_back();
        cout << a << " " << b << "; #" << mp[b] << endl;
    }
    return 0;
}