#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\An_Infinite_Graph.cpp"
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000005;
vector<int> primes;
bool isPrime[MAX_N];
vector<pair<int, int>> nodes;

void sieve()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p < MAX_N; ++p)
    {
        if (isPrime[p])
        {
            for (int i = p * p; i < MAX_N; i += p)
            {
                isPrime[i] = false;
            }
        }
    }
    for (int i = 2; i < MAX_N; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    if(isPrime[n])
    {
        cout << 1 << endl;
        cout << n << endl;
        cout << 0 << endl;
        return;
    }
    
}

int main()
{
    sieve();
    int q;
    cin >> q;

    while (q--)
    {
        solve();
    }

    return 0;
}
