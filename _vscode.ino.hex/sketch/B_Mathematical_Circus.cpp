#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Mathematical_Circus.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        if(k%2)
        {
            cout<<"YES"<<endl;
            ll x=1;
            while(x<=n)
            {
                cout<<x<<' '<<x+1<<endl;
                x+=2;
            }
        }
        else
        {
            if(k%4==0) cout<<"NO"<<endl;
            else
            {
                cout<<"YES"<<endl;
                ll x=1;
                for(int i=1;i<=n/4;i++)
                {
                    cout<<x<<' '<<4*i<<endl;
                    x+=2;
                }
                int y=2;
                for(int i=1;i<=ceil(n/4.0);i++)
                {
                    cout<<y<<' '<<x<<endl;
                    x+=2;
                    y+=4;
                }
            }
        }
    }
    return 0;
}