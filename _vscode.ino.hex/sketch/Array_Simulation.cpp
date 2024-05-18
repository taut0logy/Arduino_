#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Array_Simulation.cpp"
#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
char pre(char c)
{
    if(c=='+'||c=='-')
        return 1;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='^')
        return 3;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Test;
    cin>>Test;
    for(int T=1;T<=Test;T++)
    {
        cout<<"Case "<<T<<": "<<endl;
        int n,k,r=0;
        cin>>n>>k;
        int a[n];
        stack<char> p;
        stack<int> s;
        for(int j=0;j<n;j++)
            cin>>a[j];
        for(int i=0;i<k;i++)
        {
            char c;
            int x,y;
            cin>>c;
            if(c=='S')
            {
                cin>>x;
                for(int i=0;i<n;i++) a[i]+=x;
            }
            if(c=='M')
            {
                cin>>x;
                for(int i=0;i<n;i++) a[i]*=x;
            }
            if(c=='D')
            {
                cin>>x;
                for(int i=0;i<n;i++) a[i]/=x;
            }
            if(c=='R') reverse(a,a+n);
            if(c=='P')
            {
                cin>>x>>y;
                swap(a[x],a[y]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i==0) cout<<a[i];
            else cout<<" "<<a[i];
        }
        cout<<endl;
    }
    return 0;
}