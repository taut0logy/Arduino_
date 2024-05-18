#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_-_A.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    deque<int> v = extract_numbers(s1);
    /* for(auto i:v) cout<<i<<" ";
    cout<<endl; */
    int b = 0, e = n - 1, r = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'R')
            r = 1 - r;
        else
        {
            if (v.empty())
            {
                cout << "error" << endl;
                return;
            }
            if (r)
                v.pop_back();
            else
                v.pop_front();
        }
    }
    if (r)
        reverse(v.begin(), v.end());
    cout << "[";
    /* if(!r){
        for(int i=b;i<=e;i++)
        {
            if(i==b) cout<<v[i];
            else cout<<","<<v[i];
        }
    }
    else
    {
        for(int i=e;i>=b;i--)
        {
            if(i==e) cout<<v[i];
            else cout<<","<<v[i];
        }
    } */
    for (int i = 0; i < v.size(); i++)
    {
        if (i == 0)
            cout << v[i];
        else
            cout << "," << v[i];
    }
    cout << "]" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}