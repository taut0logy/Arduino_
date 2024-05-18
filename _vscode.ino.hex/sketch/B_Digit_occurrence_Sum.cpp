#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Digit_occurrence_Sum.cpp"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename U>
using ordered_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    long long cnt[10] = {0};
    ordered_set<long long> s;
    for (int i = 0; i < n; i++) 
    {
        long long x;
        cin >> x;
        s.insert(x);
        while(x) 
        {
            cnt[x % 10]++;
            x /= 10;
        }
    }
    while(q--)
    {
        char c;
        cin >> c;
        if(c=='?')
        {
            long long k;
            cin >> k;
            if(s.find(k)!=s.end())
            {
                long long ans = 0;
                while(k)
                {
                    ans += cnt[k % 10];
                    k /= 10;
                }
                cout << ans << endl;
            }
            else
                cout << -1 << endl;
        }
        else if(c=='+')
        {
            long long k;
            cin >> k;
            if(s.find(k)!=s.end())
            {
                s.erase(k);
                while(k)
                {
                    cnt[k % 10]--;
                    k /= 10;
                }
            }
            else
            {
                s.insert(k);
                while(k)
                {
                    cnt[k % 10]++;
                    k /= 10;
                }
            }
        }
        else
        {
            int k;
            cin >> k;
            if(k > s.size())
            {
                continue;
            }
            auto it = s.find_by_order(k-1);
            //cout<<'-'<<*it<<endl;
            long long x = *it;
            s.erase(it);
            while(x)
            {
                cnt[x % 10]--;
                x /= 10;
            }
        }
    }
    return 0;
}
