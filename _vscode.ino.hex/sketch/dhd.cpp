#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\dhd.cpp"

#include<bits/stdc++.h>
using namespace std;

double max_sum_sequence(const vector<int>& x, double s, double k) {
    int n = x.size();
    vector<double> y(n, 0.0); // initialize y to all zeros
    double sum_y = 0.0;
    for (int i = 0; i < n - 1; i++) {
        double diff = x[i + 1] - x[i];
        double max_y = 2 * diff - y[i];
        if (max_y < s) {
            return -1; // no sequence exists
        }
        y[i + 1] = min(max_y, k);
        sum_y += y[i + 1];
    }
    return sum_y;
}

int main() {
    int n;
    double s,k;
    cin >> n >> s >> k;
    vector<int> x;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        x.push_back(a);
    }
    
    double max_sum = max_sum_sequence(x, s, k);
    if (max_sum < 0) {
        cout << "-1" << endl;
    } else {
        cout << max_sum << endl;
    }
    return 0;
}
