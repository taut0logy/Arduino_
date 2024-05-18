#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\quick_sort_02.cpp"
#include<bits/stdc++.h>
using namespace std;
void Swap(int &a,int &b)
{
    a^=b^=a^=b;
}
void partition(int a[],int l,int r,int &p)
{
    int pivot=a[l];
    int ind=l;
    for(int i=l+1;i<=r;i++)
    {
        if(a[i]<=pivot)
        {
            ind++;
        }
    }
    Swap(a[ind],a[l]);
    int i=l,j=r;
    while(i<ind && j>ind)
    {
        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<ind && j>ind)
        {
            Swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    p=ind;
}
void quicksort(int a[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int p;
    partition(a,l,r,p);
    quicksort(a,l,p-1);
    quicksort(a,p+1,r);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}