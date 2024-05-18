#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\1414_Astronomical_Database.cpp"
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    bool f;
    vector<node *> child, child2;

    node()
    {
        f = false;
        child.resize(26, NULL);
        child2.resize(10, NULL);
    }
};
class trie
{
public:
    node *root;
    trie()
    {
        root = new node();
    }
    ~trie()
    {
        del(root);
    }
    void del(node *cur)
    {
        for (int i = 0; i < 26; i++)
        {
            if (cur->child[i])
            {
                del(cur->child[i]);
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if (cur->child2[i])
            {
                del(cur->child2[i]);
            }
        }
        delete (cur);
    }
    void insert(string s)
    {
        node *cur = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                if (cur->child2[s[i] - '0'] == NULL)
                {
                    cur->child2[s[i] - '0'] = new node();
                }
                cur = cur->child2[s[i] - '0'];
            }
            else
            {
                if (cur->child[s[i] - 'a'] == NULL)
                {
                    cur->child[s[i] - 'a'] = new node();
                }
                cur = cur->child[s[i] - 'a'];
            }
        }
        cur->f = true;
    }
    bool search(string s)
    {
        node *cur = root;
        for (auto c : s)
        {
            if (c >= '0' && c <= '9')
            {
                if (cur->child2[c - '0'] == NULL)
                {
                    return false;
                }
                cur = cur->child2[c - '0'];
            }
            else
            {
                if (cur->child[c - 'a'] == NULL)
                {
                    return false;
                }
                cur = cur->child[c - 'a'];
            }
        }
        return cur->f;
    }
};
vector<string> ans;

void prn(node *cur, string s)
{
    if (ans.size() == 20)
        return;
    if (cur->f)
    {
        ans.push_back(s);
    }
    for (int i = 0; i < 10; i++)
    {
        if (cur->child2[i])
        {
            prn(cur->child2[i], s + (char)(i + '0'));
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (cur->child[i])
        {
            prn(cur->child[i], s + (char)(i + 'a'));
        }
    }
}

int main()
{
    trie t;
    t.insert("sun");
    string s;
    while (cin >> s)
    {
        string star = s.substr(1);
        if (s[0] == '+')
        {
            t.insert(star);
        }
        else
        {
            ans.clear();
            cout << star << '\n';
            node *cur = t.root;
            bool f = 1;
            for (auto c : star)
            {
                if (c >= '0' && c <= '9')
                {
                    if (cur->child2[c - '0'])
                        cur = cur->child2[c - '0'];
                    else
                    {
                        f = 0;
                        break;
                    }
                }
                else if (c >= 'a' && c <= 'z')
                {
                    if (cur->child[c - 'a'])
                        cur = cur->child[c - 'a'];
                    else
                    {
                        f = 0;
                        break;
                    }
                }
                else
                {
                    f = 0;
                    break;
                }
            }
            if (f)
            {
                prn(cur, star);
                for (auto c : ans)
                    cout << "  " << c << '\n';
            }
        }
    }
    return 0;
}