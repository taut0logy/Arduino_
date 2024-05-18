#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\pr.cpp"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        vector<vector<int>> pos(26);
        for (int i = 0; i < n; i++)
            pos[s[i] - 'a'].push_back(i);

        string order;
        for (char i = 'a'; i <= 'z'; i++)
            order += i;
        sort(order.begin(), order.end(), [&](char x, char y)
             { return pos[x - 'a'].size() > pos[y - 'a'].size(); });

        string best;
        int diff = n + 1;

        for (int cnt = 1; cnt <= 26; cnt++)
        {
            if (n % cnt != 0)
                continue;
            vector<int> free;
            string toplace;

            for (int i = 0; i < 26; i++)
            {
                char c = order[i];
                int have = pos[c - 'a'].size();
                int need = (i < cnt) ? n / cnt : 0;

                if (have > need)
                {
                    for (int j = 0; j < have - need; j++)
                        free.push_back(pos[c - 'a'][j]);
                }
                else if (have < need)
                {
                    for (int j = 0; j < need - have; j++)
                        toplace += c;
                }
            }

            assert(free.size() == toplace.size());
            if (free.size() >= diff)
                continue;

            diff = free.size();
            best = s;
            for (int i = 0; i < free.size(); i++)
                best[free[i]] = toplace[i];
        }

        assert(!best.empty());
        cout << diff << '\n';
        cout << best << '\n';
    }
}
