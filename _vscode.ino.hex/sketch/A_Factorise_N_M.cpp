#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Factorise_N_M.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    vector<ll> prime;
    ll yes[100007]={0};
    for(ll i=2;i<sqrt(100007)+1;i++)
    {
        if(yes[i]==0) 
        {
            for(ll j=i*i;j<100007;j+=i) 
            {
                yes[j]=1;
            }
        }
    }
    for(ll i=2;i<100007;i++) 
    {
        if(yes[i]==0) 
        {
            prime.push_back(i);
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n;
        if(n==2) m=7;
        else m=*upper_bound(prime.begin(),prime.end(),n);
        cout<<m<<endl;
    }
}