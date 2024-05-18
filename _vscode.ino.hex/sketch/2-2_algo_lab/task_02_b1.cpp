#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\2-2_algo_lab\\task_02_b1.cpp"
#include<bits/stdc++.h>
using namespace std;
int dirx[]={1,-1,0,0,1,-1,1,-1};
int diry[]={0,0,1,-1,1,-1,-1,1};
vector<vector<int>> shortest_distance(vector<vector<int>>&vec,int srcx,int srcy)
{
    int n=vec.size();
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
    q.push({vec[srcx][srcy],{srcx,srcy}});
    dist[srcx][srcy]=vec[srcx][srcy];
    while(!q.empty())
    {
        int d=q.top().first;
        int x=q.top().second.first;
        int y=q.top().second.second;
        q.pop();
        if(dist[x][y]<d) continue;
        for(int i=0;i<8;i++)
        {
            int nx=x+dirx[i];
            int ny=y+diry[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n)
            {
                if(dist[nx][ny]>dist[x][y]+d)
                {
                    dist[nx][ny]=dist[x][y]+d;
                    q.push({dist[nx][ny],{nx,ny}});
                }
            }
        }
    }
    return dist;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> vec(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>vec[i][j];
    }
    vector<vector<int>> dist=shortest_distance(vec,0,0);
    cout<<"Shortest distance from [0,0] to [n-1,n-1] is "<<dist[n-1][n-1]<<endl;
}