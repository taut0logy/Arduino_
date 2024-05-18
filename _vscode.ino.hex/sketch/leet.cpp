#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\leet.cpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class node {
public:
    bool f;
    vector<int> child;
    node() {
        child.resize(26, -1);
        f = false;
    }
};

class Solution {
public:
    vector<node> trie;

    void init() { trie.emplace_back(); }

    void insert(string& s) {
        int cur = 0, next;
        for (auto c : s) {
            next = trie[cur].child[c - 'a'];
            if (next == -1) {
                next = trie.size();
                trie.emplace_back();
            }
            cur = next;
        }
        trie[cur].f = true;
    }

    vector<string> v;
    int cnt;

    void recur(int ind, vector<string>& prod) {
        if (cnt == 3 || ind == -1) return;
        if (trie[ind].f) {
            v.push_back(prod[ind]);
            cnt++;
        }
        for (int i = 0; i < 26; i++) recur(trie[ind].child[i], prod);
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        init();
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        int cur = 0;
        for (char c : searchWord) {
            int& next = trie[cur].child[c - 'a'];
            if (next == -1) {
                ans.emplace_back();
                cur = -1;
            } else {
                v.clear();
                cur = next;
                cnt = 0;
                recur(cur, products);
                ans.push_back(v);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord = "mouse";
    vector<vector<string>> result = solution.suggestedProducts(products, searchWord);

    for (const auto& vec : result) {
        for (const string& str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
