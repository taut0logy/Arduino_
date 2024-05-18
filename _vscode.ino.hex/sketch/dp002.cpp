#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\dp002.cpp"
#include <bits/stdc++.h>
using namespace std;
 /* There are N integers A1 ,A2 ,...,AN, written on a blackboard.We will repeat the following operation N−1 times so that we have only one integer on the blackboard.Choose two integers x and y on the blackboard and erase these two integers. Then, write a new integer x−y.Find the maximum possible value of the final integer. */
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    vector<pair<ll,ll>> ans;

    return 0;
}