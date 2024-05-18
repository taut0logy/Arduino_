#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\fhf.cpp"
// Problem: D. Moscow Gorillas
// Contest: Codeforces - Codeforces Round #852 (Div. 2)
// URL: https://codeforces.com/contest/1793/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define int long long
using ll = long long;
auto st_time = std::chrono::steady_clock::now();
signed Time() { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - st_time).count(); }
void print_time() { fprintf(stderr, "Time = %d\n", Time()); }
#define py puts("YES")
#define pn puts("NO")
#define pf puts("-1")
#define hh puts("")
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define ep emplace
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define fo(i, a, b) for (int i = (a); i <= (int)(b) - 1; ++i)
using vi = std::vector<int>;
using namespace std;
const int N = 2e5 + 5;
int n, p[N], q[N], posp[N], posq[N];
void solve(int Case) {
	cin >> n;
	rep(i, 1, n) cin >> p[i], posp[p[i]] = i;
	rep(i, 1, n) cin >> q[i], posq[q[i]] = i;
	int res = 1;
	int l = min(posp[1], posq[1]), r = max(posp[1], posq[1]);
	res += l * (l - 1) / 2;
	res += (n - r + 1) * (n - r) / 2;
	res += (r - l) * (r - l - 1) / 2;
	rep(i, 2, n) {
		int L = posp[i], R = posq[i];
		if (L > R) swap(L, R);
		if ((l > L || L > r) && (l > R || R > r)) {
			if (L > r) res += (L - r) * l;
			else if (R < l) res += (l - R) * (n - r + 1);
			else res += (R - r) * (l - L);
		}
		l = min(l, L);
		r = max(r, R);
	}
	cout << res;
}
int32_t main() {
	st_time = chrono::steady_clock::now();
	atexit(print_time);
	int Testcase = 1;
	// cin >> Testcase;
	for (int Case = 1; Case <= Testcase; ++Case) {
		solve(Case);
	}
	return 0;
}