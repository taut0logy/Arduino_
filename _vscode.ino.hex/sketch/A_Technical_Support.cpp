#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Technical_Support.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,cnt=0;
        cin>>n;
        string arr;
        cin>>arr;
        for(int i=0;i<n;i++)
        {
           if(arr[i]=='Q')
           {
               cnt++;
           }
           if(arr[i]=='A' && cnt>0)
           {
               cnt--;
           }
        }
        if(cnt>0)
        {
            cout<<"No";
        }
        else
        {
            cout<<"Yes";
        }
        cout<<endl;
    }
    return 0;
}
//QAAQQQAA
