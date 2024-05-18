#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\04team.cpp"
#include <cstdio>
#include <algorithm>
using namespace std;
long n, m, ans, ans1, tot1, tot2;
bool vis[100010];
long l[100010], r[100010];
int main()
{
    // freopen("in.in","r",stdin);
    long T;
    scanf("%ld", &T);
    while (T--)
    {
        scanf("%ld %ld", &n, &m);
        ans1 = ans = tot1 = tot2 = 0;
        for (int i = 1; i <= m; i++)
            vis[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            long a;
            scanf("%ld", &a);
            if (a > 0)
            {
                if (!vis[a])
                {
                    vis[a] = 1;
                    ans++;
                }
            }
            if (a == -1)
                tot1++;
            if (a == -2)
                tot2++;
        }
        l[0] = 0;
        r[m + 1] = 0;
        for (int i = 1; i <= m; i++)
            if (!vis[i])
                l[i] = l[i - 1] + 1;
            else
                l[i] = l[i - 1];
        for (int i = m; i >= 1; i--)
            if (!vis[i])
                r[i] = r[i + 1] + 1;
            else
                r[i] = r[i + 1];
        for (int i = 1; i <= m; i++)
            if (vis[i])
                ans1 = max(ans1, min(l[i - 1], tot1) + min(r[i + 1], tot2));
        printf("%ld\n", min(m, max(ans + ans1, max(ans + tot1, ans + tot2))));
    }

    return 0;
}