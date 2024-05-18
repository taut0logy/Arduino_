#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_-_Left_Right.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int cs=0;
    while(cs++<T)
    {
        int n,ans=0;
        cin>>n;
        vector<int> a,b;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            a.push_back(x);
            b.push_back(y);
        }
        for(int i=0;i<n;i++)
        {
            ans^=abs(a[i]-b[i])-1;
        }
        cout<<"Case "<<cs<<": ";
        cout<<((ans)?"Alice":"Bob")<<endl;
    }
    return 0;
}