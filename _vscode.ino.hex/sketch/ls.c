#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\ls.c"
#include <bits/stdc++.h>
using namespace std;

int n, k, q, a[1000005];

bool check(int l, int r) {
    int sum = 0;
    for (int i = l; i <= r; i++) {
        sum += a[i];
    }
    return sum % k == 0;
}

int main() {
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (check(l, r)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
