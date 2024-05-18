#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\6_1.c"
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    int cnt[10]={0};
    int m=n;
    while(m>0)
    {
        cnt[m%10]++;
        m=m/10;
    }
    for(int i=0;i<10;i++)
    {
        printf("Frequency of %d in n is %d\n",i,cnt[i]);
    }
    return 0;
}