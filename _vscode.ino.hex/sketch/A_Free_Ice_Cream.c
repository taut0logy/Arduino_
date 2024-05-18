#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Free_Ice_Cream.c"
#include <stdio.h>
int main()
{
    int n, cnt = 0;
    char c;
    long long k = 0, x = 0;
    scanf("%d%lld", &n, &x);
    for (int i = 0; i < n; i++)
    {
        scanf(" %c%lld", &c,&k);
        if (c == '+')
            x += k;
        else if (x - k >= 0)
        {
            x -= k;
        }
        else
        {
            cnt++;
        }
    }
    printf("%lld %d", x, cnt);
    return 0;
}