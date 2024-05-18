#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Guilty_Prince.cpp"
#include <bits/stdc++.h>
using namespace std;
int dfs(int x,int y,vector<vector<char>>&v,int n,int m)
{
    if(x<0 || x>=n || y<0 || y>=m || (v[x][y]!='.' && v[x][y]!='@')) return 0;
    v[x][y]='#';
    int cnt=1;
    return 1+dfs(x+1,y,v,n,m)+dfs(x-1,y,v,n,m)+dfs(x,y+1,v,n,m)+dfs(x,y-1,v,n,m);
}
void solve()
{
    int n,m;
    cin>>m>>n;
    vector<vector<char>>v(n,vector<char>(m));
    int x,y;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
            if(v[i][j]=='@')
            {
                x=i;
                y=j;
            }
        }
    }
    cout<<dfs(x,y,v,n,m)<<endl;
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