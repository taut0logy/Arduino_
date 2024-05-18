#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\L_-_ShaatChara.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    int cs=0;
    while(cs++<T)
    {
        int n,ans=0,cnt=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            ans^=a[i];
        }
        cout<<"Case "<<cs<<": ";
        for(int i=0;i<n;i++)
        {
            ans^=a[i];
            if(ans<a[i])
            {
                cnt++;
            }
            ans^=a[i];
        }
        cout<<cnt<<endl;
    }
    return 0;
}