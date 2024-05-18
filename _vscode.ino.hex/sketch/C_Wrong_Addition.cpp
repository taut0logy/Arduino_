#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\C_Wrong_Addition.cpp"
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string a,s;
    cin>>a>>s;
    int i=a.size()-1,j=s.size()-1;
    deque<char> dq;
    while( j>=0)
    {
        if(i<0)
        {
            //cout<<"-1"<<endl;
            dq.push_front(s[j]);
            j--;
        }
        else if(a[i]<=s[j])
        {
            dq.push_front(s[j]-a[i]+'0');
            i--;
            j--;
        }
        else
        {
            if(j-1<0 || s[j-1]=='0')
            {
                cout<<"-1"<<endl;
                return;
            }
            string temp="";
            temp+=s[j-1];
            temp+=s[j];
            int x=stoi(temp);
            if(x<10)
            {
                cout<<"-1"<<endl;
                return;
            }
            if(x-a[i]+'0'<10 && x-a[i]+'0'>=0)
            {
                dq.push_front(x-a[i]+'0'+'0');
                i--;
                j-=2;
            }
            else
            {
                cout<<"-1"<<endl;
                return;
            }
        }
    }
    if(i>=0)
    {
        cout<<"-1"<<endl;
        return;
    }
    bool f=false;
    for(auto x:dq)
    {
        if(x!='0') f=true;
        if(f) cout<<x;
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    int test = t;
    while (t--)
    {
        solve();
    }
    return 0;
}