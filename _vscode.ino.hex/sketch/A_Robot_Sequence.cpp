#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Robot_Sequence.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,ans=0;
    cin>>n;
    string s;
    cin>>s;
    map<pair<int,int>,int> m;
    m[{0,0}]=1;
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L') x--;
        else if(s[i]=='R') x++;
        else if(s[i]=='U') y++;
        else y--;
        ans+=m[{x,y}];
        m[{x,y}]++;
        //ans+=m[{x,y}];
    }
    cout<<ans<<endl;
    return 0;
}