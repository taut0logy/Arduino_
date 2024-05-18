#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Rebellion.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    int test=t;
    while(t--)
    {
        int n,cnt=0,one=0,zero=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==0) zero++;
        }
        if(is_sorted(a,a+n))
        {
            cout<<0<<endl;
            continue;
        }
        cnt=zero;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0) zero--;
            if(a[i]==1) one++;
            cnt=min(cnt,max(zero,one));
        }
        cout<<min(one,cnt)<<endl;
    }
    return 0;
}
