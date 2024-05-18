#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Circle_in_Square.cpp"
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
        cout<<"Case "<<T<<": ";
        double n;
        cin>>n;
        double ans=4*n*n-pi*n*n;
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    return 0;
}