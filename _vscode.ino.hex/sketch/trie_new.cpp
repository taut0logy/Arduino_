#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\trie_new.cpp"
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int flag;
    vector<node *> child;
    node()
    {
        flag = 0;
        child.resize(26, NULL);
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
    void insert(string s)
    {
        node *cur = root;
        for (int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'a';
            if (cur->child[idx] == NULL)
            {
                cur->child[idx] = new node();
            }
            cur = cur->child[idx];
        }
        cur->flag = 1;
    }
    bool search(string s)
    {
        node *cur = root;
        for (int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'a';
            if (cur->child[idx] == NULL)
            {
                return false;
            }
            cur = cur->child[idx];
        }
        return cur->flag;
    }

    void remove(string s)
    {
        node *cur = root;
        for (int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'a';
            if (cur->child[idx] == NULL)
            {
                return;
            }
            cur = cur->child[idx];
        }
        cur->flag = 0;
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
        delete cur;
    }
    void printAll(node *cur, string s)
    {
        if (cur->flag)
        {
            cout << s << endl;
        }
        for (int i = 0; i < 26; i++)
        {
            if (cur->child[i])
            {
                printAll(cur->child[i], s + char(i + 'a'));
            }
        }
    }
};

string longestCommonSubstring(vector<string> &strs)
{
    trie t;
    for (auto s : strs)
    {
        int n = s.size();
        for (int j = n - 1; j >= 0; j--)
        {
            t.insert(s.substr(j));
        }
    }

    string commonSubstring = "";
    int maxLength = 0;

    for (auto s : strs)
    {
        int n = s.size();
        for (int j = 0; j < n; j++)
        {
            node *cur = t.root;
            int length = 0;
            for (int k = j; k < n; k++)
            {
                int idx = s[k] - 'a';
                if (cur->child[idx] == NULL)
                {
                    break;
                }
                cur = cur->child[idx];
                length++;
                if (length > maxLength)
                {
                    maxLength = length;
                    commonSubstring = s.substr(j, length);
                }
            }
        }
    }

    return commonSubstring;
}


int main()
{
    trie t;
    t.insert("hello");
    t.insert("hell");
    t.insert("helloworld");
    t.insert("hellboy");
    cout << t.search("hell") << endl;
    t.remove("hell");
    cout << t.search("hell") << endl;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonSubstring(strs) << endl;
    return 0;
}