#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Adding_Digits.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b,n;
    cin>>a>>b>>n;
    for(ll i=0;i<10;i++)
        if((a*10+i)%b==0)
        {
            cout<<a*10+i;
            for(ll j=0;j<n-1;j++)
            {
                cout<<0;
            }
            cout<<endl;
            return 0;
        }
    cout<<-1<<endl;
    return 0;
}