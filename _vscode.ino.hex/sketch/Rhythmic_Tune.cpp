#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Rhythmic_Tune.cpp"
#include <bits/stdc++.h>
using namespace std;


vector<int> computeLPS(const string &pattern)
{
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int maxPatternLength = 0;
    vector<int> lps = computeLPS(s);
    for (int i = 0; i < n; i++)
    {
        string sub=s.substr(i,n-i);
        int m = sub.size();
        vector<int> lps = computeLPS(sub);
        for(int j=0;j<m;j++)
        {
            int p=lps[j];
            if(p>0 && (j+1)%(j+1-p)==0)
                maxPatternLength=max(maxPatternLength,j+1);
        }
    }
    cout << maxPatternLength << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Test, TT = 0;
    cin >> Test;
    while (TT++ < Test)
    {
        // cout<<"Case "<<TT<<": ";
        solve();
    }
    return 0;
}