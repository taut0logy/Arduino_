#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\quicksort_practice.cpp"
#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int n,int b,int e)
{
    int pivot=a[b],ind=b;
    for(int i=b+1;i<=e;i++)
    {
        if(a[i]>=a[b]) ind++;
    }
    int i=b,j=e;
    while(i<j)
    {
        
    }
    return ind;
}