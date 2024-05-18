#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\False_Ordering.cpp"
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
int divisorcnt(int n)
{
    int cnt=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i*i==n)
            {
                cnt++;
            }
            else
            {
                cnt+=2;
            }
        }
    }
    return cnt;
}
bool comp(int a,int b)
{
    if(divisorcnt(a)==divisorcnt(b))
    {
        return a>b;
    }
    return divisorcnt(a)<divisorcnt(b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Test,TT = 0;
    cin >> Test;
    vector<int> v(1000);
    iota(all(v),1);
    sort(all(v),comp);
    while (TT++<Test)
    {
        cout<<"Case "<<TT<<": ";
        int n;
        cin>>n;
        cout<<v[n-1]<<endl;
    }
    return 0;
}