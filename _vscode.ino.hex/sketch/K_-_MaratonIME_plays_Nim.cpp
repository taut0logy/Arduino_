#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\K_-_MaratonIME_plays_Nim.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    while(x>0 || y>0)
    {
        int a,b;
        printf("%d %d\n",(x>y?1:2),abs(x-y));
        fflush(stdout);
        (x>y)?(x-=abs(x-y)):(y-=abs(x-y));
        scanf("%d%d",&a,&b);
        if(a==1) x-=b;
        else y-=b;
    }
    return 0;
}