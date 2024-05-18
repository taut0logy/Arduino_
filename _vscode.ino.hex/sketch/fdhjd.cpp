#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\fdhjd.cpp"
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define rng(v) v.begin(),v.end()
#define rngr(v) v.rbegin(),v.rend()
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using P3 = tuple<int, int, int>;
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vs vector<string>
using vp = vector<P>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using CP = complex<double>;
double dot( const CP &z, const CP &w ){ return (z.real()*w.real() + z.imag()*w.imag()); }
double cross( const CP &z, const CP &w ){ return (z.real()*w.imag() - z.imag()*w.real()); }
template<class T> inline bool is_in(T x, T a, T b) {return a <= x && x < b;}
// #include <bits/stdc++.h>
// using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// #define rep(i,n) for (int i = 0; i < (n); ++i)
// using mint = modint998244353;
using T = tuple<int, int, int>;
using vt = vector<T>;
 
int main() {
  int n, m;
  cin >> n >> m;
  vs d;
  int l = 0;
  rep(i, n) {
    string s;
    cin >> s;
    l += sz(s);
    d.eb(s);
  }
  set<string> st;
  rep(i, m) {
    string s;
    cin >> s;
    st.emplace(s);
  }
  vi v;
  rep(i, n) v.eb(i);
  string ans;
  do {
    //string x;
    int r = n-1+l;
    if(16-r < 0) {
      cout << "-1" << endl;
      return 0;
    }
    int R = 16-r;
    auto dfs = [&](auto f, int i, string s, int k) -> string {
      // if(i == 0) {
      //   string t = f(f, i+1, d[v[0]], k);
      //   return t;
      // }
      if(i == n-1) {
        string a = s+d[v[i]];
        if(st.count(a) || sz(a) < 3 || sz(a) > 16) return "";
        else return a;
      }
      string y = s+d[v[i]]+"_";
      string t = f(f, i+1, y, k);
      if(sz(t)) return t;
      if(k <= 0) return "";
      rep(ki, k) {
        //string y = d[v[i]]+u;
        y+= "_";
        string t = f(f, i+1, y, k-ki-1);
        if(sz(t)) return t;
      }
      return "";
    } ;
    // rep(b, 1<<(n-1)) {
    //   rep(i, n) {
    //     x += d[v[i]];
    //     if(i < n-1) x += "_";
    //   }
    // }
    // if(!st.count(x)) {
    //   ans = x;
    //   break;
    // }
    string x = dfs(dfs, 0, "", R);
    if(sz(x)) {
      ans = x;
      break;
    }
  } while (next_permutation(v.begin(), v.end()));
  if(sz(ans) == 0) ans = "-1";
  cout << ans << endl;
  // vi d;
  // rep(i, m) {
  //   int x = 1;
  //   int y = 5;
  //   int z =x*y*i;
  //   d.eb(z);
  // }
  // cout << "done" << endl;
  return 0;
}
 
#if 0
11
ADD 3
SAVE 1
ADD 4
SAVE 2
LOAD 1
DELETE
DELETE
LOAD 2
SAVE 1
LOAD 3
LOAD 1
 
3 3 4 4 3 -1 -1 4 4 -1 4
 
#endif
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define rng(v) v.begin(),v.end()
#define rngr(v) v.rbegin(),v.rend()
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using P3 = tuple<int, int, int>;
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vs vector<string>
using vp = vector<P>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using CP = complex<double>;
double dot( const CP &z, const CP &w ){ return (z.real()*w.real() + z.imag()*w.imag()); }
double cross( const CP &z, const CP &w ){ return (z.real()*w.imag() - z.imag()*w.real()); }
template<class T> inline bool is_in(T x, T a, T b) {return a <= x && x < b;}
// #include <bits/stdc++.h>
// using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// #define rep(i,n) for (int i = 0; i < (n); ++i)
// using mint = modint998244353;
using T = tuple<int, int, int>;
using vt = vector<T>;

int main() {
  int n, m;
  cin >> n >> m;
  vs d;
  int l = 0;
  rep(i, n) {
    string s;
    cin >> s;
    l += sz(s);
    d.eb(s);
  }
  set<string> st;
  rep(i, m) {
    string s;
    cin >> s;
    st.emplace(s);
  }
  vi v;
  rep(i, n) v.eb(i);
  string ans;
  do {
    //string x;
    int r = n-1+l;
    if(16-r < 0) {
      cout << "-1" << endl;
      return 0;
    }
    int R = 16-r;
    auto dfs = [&](auto f, int i, string s, int k) -> string {
      // if(i == 0) {
      //   string t = f(f, i+1, d[v[0]], k);
      //   return t;
      // }
      if(i == n-1) {
        string a = s+d[v[i]];
        if(st.count(a) || sz(a) < 3 || sz(a) > 16) return "";
        else return a;
      }
      string y = s+d[v[i]]+"_";
      string t = f(f, i+1, y, k);
      if(sz(t)) return t;
      if(k <= 0) return "";
      rep(ki, k) {
        //string y = d[v[i]]+u;
        y+= "_";
        string t = f(f, i+1, y, k-ki-1);
        if(sz(t)) return t;
      }
      return "";
    } ;
    // rep(b, 1<<(n-1)) {
    //   rep(i, n) {
    //     x += d[v[i]];
    //     if(i < n-1) x += "_";
    //   }
    // }
    // if(!st.count(x)) {
    //   ans = x;
    //   break;
    // }
    string x = dfs(dfs, 0, "", R);
    if(sz(x)) {
      ans = x;
      break;
    }
  } while (next_permutation(v.begin(), v.end()));
  if(sz(ans) == 0) ans = "-1";
  cout << ans << endl;
  // vi d;
  // rep(i, m) {
  //   int x = 1;
  //   int y = 5;
  //   int z =x*y*i;
  //   d.eb(z);
  // }
  // cout << "done" << endl;
  return 0;
}

#if 0
11
ADD 3
SAVE 1
ADD 4
SAVE 2
LOAD 1
DELETE
DELETE
LOAD 2
SAVE 1
LOAD 3
LOAD 1

3 3 4 4 3 -1 -1 4 4 -1 4

#endif