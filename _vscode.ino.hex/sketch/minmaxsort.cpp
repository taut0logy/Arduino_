#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\minmaxsort.cpp"
#include<bits/stdc++.h>
using namespace std;
void Swap(int &a, int &b)
{
    a^=b^=a^=b;
}
void findmin(int a[], int n, int x, int y, int &pos)
{
    for(int i=x+1;i<=y;i++)
        if(a[i]<a[pos])
            pos=i;
}
void findmax(int a[], int n, int x, int y, int &pos)
{
    for(int i=x-1;i>=y;i--)
        if(a[i]>a[pos])
            pos=i;
}
void minMaxSort(int a[], int n)
{
    int min=0, max=n-1;
    for(int i=0;i<n/2;i++)
    {
        int pos=min;
        findmin(a,n,min,max,pos);
        if(pos != min)
            Swap(a[min],a[pos]);
        pos=max;
        findmax(a,n,max,min,pos);
        if(pos != max)
            Swap(a[max],a[pos]);
        min++;
        max--;
    }
    
}
int main()
{
    int n=5;
    int a[n]={4,3,6,3,1};
    minMaxSort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}