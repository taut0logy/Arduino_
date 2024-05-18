#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\ICPC preli\\g.c"
#include <stdio.h>
#include <string.h>

void solve()
{
    char s[101];
    scanf("%s", s);
    int ans = 0, W = 0;
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if (s[i] != 'W')
        {
            ans += s[i] - '0';
        }
        else
        {
            W++;
        }
    }
    char o1[] = " Over \0", o2[] = " Overs \0", r1[] = " Run \0", r2[] = " Runs \0", w1[] = " Wicket.\0", w2[] = " Wickets.\0";
    int olen = 0, rlen = 0, wlen = 0;
    if (ans <= 1)
        rlen = 1;

    if (W <= 1)
        wlen = 1;

    if (length <= 6)
        olen = 1;

    printf("%d.%d%s%d%s%d%s\n", length / 6, length % 6, (olen ? o1 : o2), ans, (rlen ? r1 : r2), W, (wlen ? w1 : w2));
}

int main()
{
    int Test, TT = 0;
    scanf("%d", &Test);
    while (TT++ < Test)
    {
        // printf("Case %d: ", TT);
        solve();
    }
    return 0;
}