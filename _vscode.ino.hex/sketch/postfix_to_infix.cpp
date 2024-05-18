#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\postfix_to_infix.cpp"
#include <bits/stdc++.h>
using namespace std;
string postfixtoinfix(string &s)
{
    stack<string> st;
    int n = s.size();
    string ans;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c >= 'a' && c <= 'z')
        {
            string ss;
            ss += c;
            st.push(ss);
        }
        else
        {
            string str1 = st.top();
            st.pop();
            string str2 = st.top();
            st.pop();
            string sign;
            sign+=c;
            string ans = "(" + str2 + sign + str1 + ")";
            st.push(ans);
        }
    }
    ans = st.top();
    return ans;
}
int main()
{
    string s;
    cin >> s;
    string ans = postfixtoinfix(s);
    cout << ans << endl;

    return 0;
}