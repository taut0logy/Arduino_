#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Add_Plus_Minus_Sign.cpp"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        int sum=arr[0]-'0';
        for(int i=0;i<n-1;i++)
        {
            if(sum<=0)
            {
                cout<<'+';
                sum+=arr[i+1]-'0';
            }
            else
            {
                cout<<'-';
                sum-=arr[i+1]-'0';
            }   
        }
        cout<<endl;
    }
    return 0;
}