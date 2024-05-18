#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\heap_practice.cpp"
#include<bits/stdc++.h>
using namespace std;
void insert(int a[],int &n,int x)
{
    int i=n++;
    a[i]=x;
    while(i>0)
    {
        int par=(i-1)/2;
        if(a[par]<a[i])
        {
            swap(a[i],a[par]);
            i=par;
        }
        else return;
    }
}
void del(int a[],int n)
{
    if(!n) return;
    a[0]=a[--n];
    int par=0;
    while(par<n)
    {
        int l=2*par+1,r=2*par+2;
        if(l<n && a[par]<a[l])
        {
            swap(a[par],a[l]);
            par=l;
        }
        else if(r<n && a[par]<a[r])
        {
            swap(a[par],a[r]);
            par=r;
        }
        else return;
    }
}
void heapify(int a[],int n, int i)
{
    int p=0;
    int l=2*p+1,r=2*p+2;
    if(l<n && a[p]<a[l]) p=l;
    if(r<n && a[p]<a[r]) p=r;
    if(p!=i)
    {
        swap(a[p],a[i]);
        heapify(a,n,p);
    }
}
void heapsort(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(int i=n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
int main()
{
    int a[100];
    int n=0;
    insert(a,n,10);
    insert(a,n,20);
    insert(a,n,30);
    insert(a,n,40);
    insert(a,n,50);
    insert(a,n,60);
    insert(a,n,70);


    int arr[5] = {54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}