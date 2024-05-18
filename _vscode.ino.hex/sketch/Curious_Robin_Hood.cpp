#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Curious_Robin_Hood.cpp"
#include<bits/stdc++.h>
using namespace std;

void build(vector<int>&tree,int ind,int l,int r,vector<int>&v)
{
    if(l==r)
    {
        tree[ind]=v[l];
        return;
    }
    int mid=(l+r)/2;
    build(tree,2*ind+1,l,mid,v);
    build(tree,2*ind+2,mid+1,r,v);
    tree[ind]=tree[2*ind+1]+tree[2*ind+2];
}

void update1(vector<int>&tree,int ind,int l,int r,int pos)
{
    if(l==r)
    {
        cout<<tree[ind]<<endl;
        tree[ind]=0;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        update1(tree,2*ind+1,l,mid,pos);
    else
        update1(tree,2*ind+2,mid+1,r,pos);
    tree[ind]=tree[2*ind+1]+tree[2*ind+2];
}

void update2(vector<int>&tree,int ind,int l,int r,int pos,int val)
{
    if(l==r)
    {
        tree[ind]+=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        update2(tree,2*ind+1,l,mid,pos,val);
    else
        update2(tree,2*ind+2,mid+1,r,pos,val);
    tree[ind]=tree[2*ind+1]+tree[2*ind+2];
}

int query(vector<int>&seg,int ind,int bg,int en,int l,int r)
{
    if(l>en || r<bg) return 0;
    if(l<=bg && r>=en) return seg[ind];
    int mid=(bg+en)/2;
    int left=query(seg,2*ind+1,bg,mid,l,r);
    int right=query(seg,2*ind+2,mid+1,en,l,r);
    return left+right;
}

void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(auto &x:v)
        cin>>x;
    vector<int> tree(4*n);
    build(tree,0,0,n-1,v);
    for(int i=0;i<q;i++)
    {
        int k;
        cin>>k;
        if(k==1)
        {
            int ind;
            cin>>ind;
            update1(tree,0,0,n-1,ind);
        }
        else if(k==2)
        {
            int pos,val;
            cin>>pos>>val;
            update2(tree,0,0,n-1,pos,val);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<query(tree,0,0,n-1,l,r)<<endl;
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
        cout<<"Case "<<TT<<": "<<endl;
        solve();
    }
    return 0;
}