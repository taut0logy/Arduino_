#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\lab005.cpp"
#include<bits/stdc++.h>
using namespace std;
void Swap(int &a, int &b)
{
    a^=b^=a^=b;
}
void findmin(int a[], int n, int x, int &pos)
{
    for(int i=x+1;i<n;i++)
        if(a[i]<a[pos])
            pos=i;
}
void selectionSort(int a[], int n)
{
    int pos;
    for(int i=0;i<n-1;i++)
    {
        pos=i;
        findmin(a,n,i,pos);
        if(pos != i)
            Swap(a[i],a[pos]);
    }
}
int main()
{
    int n=5;
    int a[n]={4,3,6,3,1};
    selectionSort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
