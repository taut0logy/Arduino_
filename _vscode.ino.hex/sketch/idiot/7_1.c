#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\7_1.c"
#include<stdio.h>
void print(int n)
{
    if(n==0)
    {
        return;
    }
    print(n-1);
    printf("%d ",n);
}
int main()
{
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    printf("Natural numbers upto %d are: ",n);
    print(n);
}