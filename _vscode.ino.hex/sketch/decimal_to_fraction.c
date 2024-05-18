#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\decimal_to_fraction.c"
#include<stdio.h>
#include<math.h>

int gcd(int a, int b)
{
    int x=(a<b)?a:b;
    while(x>0)
    {
        if(a%x==0 && b%x==0) break;
        x--;
    }
    return x;
}
//precise up to .0000001
void decitofrac (double n)
{
    double full=floor(n);
    double frac=n-full;
    long num=(frac*1000000)/gcd(1000000,(frac*1000000));
    long denominator=1000000/gcd(1000000,(frac*1000000));
    long numerator=full*denominator+num;
    printf("%ld/%ld",numerator,denominator);
}
int main()
{
    double x;
    scanf("%d",&x);
    decitofrac(x);
    return 0;
}