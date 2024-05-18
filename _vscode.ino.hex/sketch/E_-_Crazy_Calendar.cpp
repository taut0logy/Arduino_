#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\E_-_Crazy_Calendar.cpp"
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
        int n,m,ans=0;
        cin>>n>>m;
        int p;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>p;
                int x=n-i-1,y=m-j-1;
                if(x%2+y%2==1)
                {
                    ans^=p;
                }
            }
        }
        cout<<"Case "<<cs<<": ";
        cout<<(ans?"win":"lose")<<endl;
    }
    return 0;
}