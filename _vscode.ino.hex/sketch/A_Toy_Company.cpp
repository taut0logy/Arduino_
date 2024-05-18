#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Toy_Company.cpp"
#include <bits/stdc++.h>
using namespace std;
int dirx[]={0,0,1,0,0,-1};
int diry[]={0,1,0,0,-1,0};
int dirz[]={1,0,0,-1,0,0};
void solve()
{
    string s,e;
    cin>>s>>e;
    int n;
    cin>>n;
    map<string,int>vis;
    for(int i=0;i<n;i++)
    {
        string a,b,c;
        cin>>a>>b>>c;
        for(int j=0;j<a.size();j++)
        {
            for(int k=0;k<b.size();k++)
            {
                for(int l=0;l<c.size();l++)
                {
                    string temp;
                    temp+=a[j];
                    temp+=b[k];
                    temp+=c[l];
                    vis[temp] = -1;
                }
            }
        }
    }
    if(vis[s]==-1 || vis[e]==-1)
    {
        cout<<-1<<endl;
        return;
    }
    map<string,int> time;
    time[s] = 0;
    queue<string>q;
    q.push(s);
    string u;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(u==e)
        {
            cout<<time[u]<<endl;
            return;
        }
        for(int i=0;i<6;i++)
        {
            string v;
            v+=u[0]+dirx[i];
            v+=u[1]+diry[i];
            v+=u[2]+dirz[i];
            if(v[0]<'a') v[0]='z';
            if(v[0]>'z') v[0]='a';
            if(v[1]<'a') v[1]='z';
            if(v[1]>'z') v[1]='a';
            if(v[2]<'a') v[2]='z';
            if(v[2]>'z') v[2]='a';
            if(!vis[v])
            {
                vis[v]=1;
                time[v] = time[u]+1;
                q.push(v);
            }
        }
    }
    cout<<-1<<endl;

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