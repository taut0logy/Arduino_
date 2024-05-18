#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_-_Matrix_Game.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int cs=0;
    while(cs++<T)
    {
        int n,m,ans=0;
        cin>>n>>m;
        int a[n]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x;
                cin>>x;
                a[i]+=x;
            }
        }
        for(int i=0;i<n;i++)
        {
            ans^=a[i];
        }
        cout<<"Case "<<cs<<": ";
        cout<<(ans?"Alice":"Bob")<<endl;
    }
    return 0;
}