#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Binary_Simulation.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    string s;
    cin>>s;
    ll n=s.size();
    vector<int>seg(4*n);
    function<void(int,int,int,int,int)>update=[&](int id,int b,int e,int l,int r)
    {
        if(b>r || e<l)
        {
            return;
        }
        if(b>=l && e<=r)
        {
            seg[id]++;
            return;
        }
        int mid=(b+e)/2;
        update(2*id,b,mid,l,r);
        update(2*id+1,mid+1,e,l,r);
    };
    function<void(int,int,int,int)>query=[&](int id,int pos,int l,int r)
    {
        if(seg[id] && l!=r)
        {
            seg[2*id]+=seg[id];
            seg[2*id+1]+=seg[id];
            seg[id]=0;
        }
        if(l<=pos && pos<=r)
        {
            if(l==r)
            {
                if(seg[id]%2)
                {
                    s[pos]=(s[pos]=='0'?'1':'0');
                }
                seg[id]=0;
                return;
            }
            int mid=(l+r)/2;
            query(2*id,pos,l,mid);
            query(2*id+1,pos,mid+1,r);
        }
    };
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        char c;
        cin>>c;
        if(c=='I')
        {
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            update(1,0,n-1,l,r);
        }
        if(c=='Q')
        {
            int idx;
            cin>>idx;
            idx--;
            query(1,idx,0,n-1);
            cout<<s[idx]<<endl;
        }
    }
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
        cout<<"Case "<<TT<<":\n";
        solve();
    }
    return 0;
}