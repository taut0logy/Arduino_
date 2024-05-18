#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\check_if_n_ans_its_double_exist.cpp"
#include <bits/stdc++.h>
using namespace std;
int bs(vector<int> v, int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (v[m] == x)
            return m;
        if (v[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
bool checkIfExist(vector<int>& arr) 
{
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        int x=bs(arr,0,n-1,2*arr[i]);
        if(x!=i && x!=-1) return true;
    }
    return false;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
    }
    cout<<((checkIfExist(v))?"YES":"NO")<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    int test = t;
    while (t--)
    {
        solve();
    }
    return 0;
}