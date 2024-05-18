#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\bubble_sort.cpp"
#include<bits/stdc++.h>
using namespace std;
void Swap(int &a, int &b)
{
    a^=b^=a^=b;
}
void bubbleSort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
                Swap(a[j],a[j+1]);
}
int main()
{
    int n=5;
    int a[n]={4,3,6,3,1};
    bubbleSort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}