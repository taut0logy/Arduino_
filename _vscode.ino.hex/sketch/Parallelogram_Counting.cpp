#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Parallelogram_Counting.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int parallelogramcnt(int a[][2],int n,map<pair<int,int>,int> mp)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int x=a[i][0]+a[k][0]-a[j][0];
                int y=a[i][1]+a[k][1]-a[j][1];
                if(mp[{x,y}])
                {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
void solve()
{
    int n;
    cin>>n;
    int a[n][2];
    map<pair<int,int>,int> mp;
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
        mp[{a[i][0],a[i][1]}]++;;
    }
    cout<<parallelogramcnt(a,n,mp)<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Test,TT = 0;
    cin >> Test;
    while (TT++<Test)
    {
        cout<<"Case "<<TT<<": ";
        solve();
    }
    return 0;
}