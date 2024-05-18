#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\ICPC preli\\g2.c"
#include <stdio.h>
#include <string.h>

void solve() {
    char s[101];
    scanf("%s", s);
    int ans = 0, W = 0;
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        if (s[i] != 'W') {
            ans += s[i] - '0';
        } else {
            W++;
        }
    }
    char o[10], r[10], w[10];
    
    if (ans <= 1) {
        strcpy(r, " Run ");
    } else {
        strcpy(r, " Runs ");
    }

    if (W <= 1) {
        strcpy(w, " Wicket.");
    } else {
        strcpy(w, " Wickets.");
    }

    if (length <= 6) {
        strcpy(o, " Over ");
    } else {
        strcpy(o, " Overs ");
    }
    printf("%d.%d%s%d%s%d%s\n", length / 6, length % 6, o, ans, r, W, w);
}

int main() {
    int Test, TT = 0;
    scanf("%d", &Test);
    while (TT++ < Test) {
        // printf("Case %d: ", TT);
        solve();
    }
    return 0;
}