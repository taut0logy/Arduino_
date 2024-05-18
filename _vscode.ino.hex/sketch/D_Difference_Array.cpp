#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\D_Difference_Array.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int diff[100005];
int a[100005];
void solve()
{
    int n,null=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    while(n>1)
    {
        int sz=0;
        if(null)
        {
            null--;
            diff[sz++]=a[0];
        }
        for(int i=0;i<n-1;i++)
        {
            if(a[i+1]-a[i])
            {
                diff[sz++]=a[i+1]-a[i];
            }
            else
            {
                null++;
            }
        }
        sort(diff,diff+sz);
        for(int i=0;i<sz;i++)
        {
            a[i]=diff[i];
        }
        n=sz;
    }
    if(n==1) cout<<a[0]<<endl;
    else cout<<0<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}