#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_1_Non-alternating_Deck_easy_version.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n,i=2;
    scanf("%lld",&n);
    n--;
    ll a=1,b=0;
    while(n)
    {
        b+=min(n,i);
        n-=i;
        i++;
        if(n<=0) break;
        b+=min(n,i);
        n-=i;
        i++;
        if(n<=0) break;
        a+=min(n,i);
        n-=i;
        i++;
        if(n<=0) break;
        a+=min(n,i);
        n-=i;
        i++;
        if(n<=0) break;
    }
    printf("%lld %lld\n",a,b);
}
int main()
{

    int t = 1;
    scanf("%d", &t);
    int test = t;
    while (t--)
    {
        solve();
    }
    return 0;
}
