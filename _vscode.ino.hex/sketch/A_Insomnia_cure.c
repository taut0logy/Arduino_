#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Insomnia_cure.c"
#include <stdio.h>
int main ()
{
    int k,l,m,n,d,i,cnt=0;
    scanf ("%d %d %d %d %d",&k,&l,&m,&n,&d);
    for (i=1;i<=d;i++)
    {
        if (i%k==0||i%l==0||i%m==0||i%n==0)
        {
            cnt++;
        }
    }
    printf ("%d",cnt);
    return 0;
}