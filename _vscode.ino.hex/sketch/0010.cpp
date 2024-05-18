#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\0010.cpp"
#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define pp pop_back
#define vsort(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define yn(flag) cout<<(flag?"YES":"NO")<<endl;
#define bg begin()
#define en end()
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef long long ll;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x,y,x1,y1,flag=0;
        cin>>x>>y>>x1>>y1;
        int p[]={x-1,x-1,x-2,x-2,x+1,x+1,x+2,x+2};
        int q[]={y+2,y-2,y+1,y-1,y+2,y-2,y+1,y-1};
        int p1[]={x1-1,x1-1,x1-2,x1-2,x1+1,x1+1,x1+2,x1+2};
        int q1[]={y1+2,y1-2,y1+1,y1-1,y1+2,y1-2,y1+1,y1-1};
        /*f(i,0,8)
        {
            if(p[i]<1 || p[i]>8)
            {
                p[i]=-10;
            }
            if(p1[i]<1 || p1[i]>8)
            {
                p1[i]=-10;
            }
            if(q[i]<1 || q[i]>8)
            {
                q[i]=-10;
            }
            if(q1[i]<1 || q1[i]>8)
            {
                q1[i]=-10;
            }
        }*/
        f(i,0,8)
        {
            f(j,0,8)
            {
                if((p[i]==p1[j]&& q[i]==q1[j]))

                        flag++;


            }
        }
        cout<<flag<<' ';
        if(flag>=2)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

