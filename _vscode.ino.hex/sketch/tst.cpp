#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\tst.cpp"
#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, k, q, a[N];
int cnt[N];

bool check(int l, int r) {
    int sum = 0;
    for (int i = l; i <= r; i++) {
        sum += a[i];
    }
    return sum % k == 0;
}

int main() {
    cin >> n >> k ;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[i % k]++;
    }
    cin>>q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        int sum = 0;
        for (int i = l; i <= r; i++) {
            sum += a[i];
        }
        int len = r - l + 1;
        if (len >= k && (sum % k == 0)) {
            int num = len / k;
            int res = 0;
            for (int i = 0; i < k; i++) {
                if (cnt[i] >= num) {
                    res++;
                }
            }
            if (res >= k) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
