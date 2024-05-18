#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\dnd.cpp"
/* 2N people numbered 1,2,…,2N attend a ball. They will group into N pairs and have a dance.If Person i and Person j pair up, where i is smaller than j, the affinity of that pair is A i,j.​If the N pairs have the affinity of B1 ,B2 ,…,BN, the total fun of the ball is the bitwise XOR of them: B1⊕B2⊕⋯⊕BN.Print the maximum possible total fun of the ball when the 2N people can freely group into N pairs. */
//https://atcoder.jp/contests/abc236/tasks/abc236_d
#include <bits/stdc++.h>
using namespace std;
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
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans^=a[i];
    }
    for(int i=0;i<n;i++)
    {
        cout << (ans^a[i]) << " ";
    }
    cout << endl;
    return 0;
}