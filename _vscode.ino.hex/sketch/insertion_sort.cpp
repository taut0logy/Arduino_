#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\insertion_sort.cpp"
#include<bits/stdc++.h>
using namespace std;
void Swap(int &a, int &b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}
void insertionSort(int a[], int n)
{
    int key;
    for(int i=1;i<n;i++)
    {
        key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main()
{
    int n=5;
    int a[n]={4,3,6,3,1};
    insertionSort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}