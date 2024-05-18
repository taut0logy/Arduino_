#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\min_max_sort.cpp"
#include<bits/stdc++.h>
using namespace std;
void findminmax(int arr[],int st,int en,int &min_i,int &max_i)
{
    min_i=st;
    max_i=st;
    int minn=arr[st];
    int maxx=arr[st];
    for(int ptr=st+1;ptr<en;ptr++)
    {
        if(arr[ptr]<minn)
        {
            min_i=ptr;
            minn=arr[ptr];
        }
        else if(arr[ptr]>maxx)
        {
            max_i=ptr;
            maxx=arr[ptr];
        }
    }
}
void minmax(int arr[],int n)
{
    int min_i,max_i;
    int i,j;
    for( i=0,j=n-1;i<j;i++,j--)
    {
        findminmax(arr,i,n-i,min_i,max_i);
        swap(arr[i],arr[min_i]);
        if(max_i==i)
        {
            max_i=min_i;
        }
        swap(arr[j],arr[max_i]);
    }
}
int main()
{
     int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    cout<<endl;
    minmax(arr, n);
    cout<<"sorted"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    return 0;
}