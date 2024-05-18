#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\dsf.cpp"
#include<bits/stdc++.h>
using namespace std;
int time[100][2];
int v=9,e;
class Stack
{
    int Top;
    int a[100];
    public:
    Stack()
    {
        Top=-1;
    }
    void push(int x)
    {
        a[++Top]=x;
    }
    void pop()
    {
        Top--;
    }
    int top()
    {
        return a[Top];
    }
    bool empty()
    {
        if(Top==-1)
        return true;
        else
        return false;
    }
};
void dfs(int graph[][100], int v, int root)
{
    bool vis[v] = {false};
    Stack s;
    s.push(root);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            s.push(i);
            while (!s.empty())
            {
                int x = s.top();
                s.pop();
                if (!vis[x])
                {
                    cout << x << " ";
                    vis[x] = true;
                }
                for (int j = 0; j < v; j++)
                {
                    if (graph[x][j] == 1 && !vis[j])
                    {
                        s.push(j);
                    }
                }
            }
            cout << endl;
        }
    }
}
int main()
{
    int v,e;
    cin>>v>>e;
    int graph[v][v]={0};
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }
    dfs(graph,v,0);
    return 0;
}