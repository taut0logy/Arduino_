#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\AE_-_Hex-a-bonacci.cpp"
#include <bits/stdc++.h>
using namespace std;
#define M 10000007
typedef long long ll;

int main()
{
    int cs;
    cin >> cs;
    for (int c = 1; c <= cs; c++)
    {
        int n;
        ll a[10005];
        for (int i = 0; i < 6; i++)
            cin >> a[i];
        cin >> n;
        for (int i = 6; i < n + 1; i++)
        {
            a[i] = (a[i - 1] + a[i - 2] + a[i - 3] + a[i - 4] + a[i - 5] + a[i - 6]) % M;
        }
        cout << "Case " << c << ": " << a[n]%M << endl;
    }
}