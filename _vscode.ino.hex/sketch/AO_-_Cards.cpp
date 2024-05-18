#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\AO_-_Cards.cpp"
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    string s,ans;
    cin>>s;
    int r=0,g=0,b=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R') r++;
        else if(s[i]=='G') g++;
        else b++;
    }
    //cout<<r<<" "<<g<<" "<<b<<endl;
    if(r && g && b)
    {
        cout<<"BGR"<<endl;
        return 0;
    }
    else if(g && b)
    {
        ans+="R";
        if(g>1) ans+="B";
        if(b>1) ans+="G";
    }
    else if(r && g)
    {
        ans+="B";
        if(r>1) ans+="G";
        if(g>1) ans+="R";
    }
    else if(r && b)
    {
        ans+="G";
        if(r>1) ans+="B";
        if(b>1) ans+="R";
    }
    else if(r)
    {
        ans+="R";
    }
    else if(g)
    {
        ans+="G";
    }
    else
    {
        ans+="B";
    }
    sort(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}