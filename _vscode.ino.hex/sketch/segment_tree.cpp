#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\segment_tree.cpp"
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
    tree[ind]=min(tree[2*ind+1],tree[2*ind+2]);
}
void update(vector<int>&tree,int ind,int l,int r,int pos,int val)
{
    //ind= index of tree
    //pos= index of array
    if(l==r)
    {
        tree[ind]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        update(tree,2*ind+1,l,mid,pos,val);
    else
        update(tree,2*ind+2,mid+1,r,pos,val);
    tree[ind]=min(tree[2*ind+1],tree[2*ind+2]);
}
int query(vector<int>&seg,int ind,int bg,int en,int l,int r)
{
    if(l>en || r<bg) return INT_MAX;
    if(l<=bg && r>=en) return seg[ind];
    int mid=(bg+en)/2;
    int left=query(seg,2*ind+1,bg,mid,l,r);
    int right=query(seg,2*ind+2,mid+1,en,l,r);
    return min(left,right);
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
        if(k==1){
        int l,r;
        cin>>l>>r;
        cout<<query(tree,0,0,n-1,l-1,r-1)<<endl;
        }
        else
        {
            int pos,val;
            cin>>pos>>val;
            update(tree,0,0,n-1,pos-1,val);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin>>test;
    for(int i=1;i<=test;i++)
    {
        cout<<"Case "<<i<<":"<<endl;
        solve();
    }
    return 0;
}
/* 
10
4 3 7 2 5 8 5 9 1 4
5
 */