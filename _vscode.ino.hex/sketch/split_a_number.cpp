#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\split_a_number.cpp"
#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define pp pop_back
#define vsort(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define yn(flag) cout<<(flag?"YES":"NO")<<endl;
#define bg begin()
#define en end()
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef long long ll;

int main()
{
    int l;
    string n;
    cin>>l>>n;
    if(l==1) cout<<n;
    else if(l%2==0)
    {
        int m=l/2;
        string n1,n2;
        f(i,0,m)
        {
            n1[i]=n[i];
        }
        f(i,m,l)
        {
            n2[i-m]=n[i];
        }
        int num1=stoi(n1),num2=stoi(n2);
        int ans=num1+num2;
        cout<<ans;
    }
    else
    {
        int m=l/2,p=(l/2)+1,num11,num12,num21,num22,ans1,ans2,ans;
        string n11,n12,n21,n22;
        f(i,0,m)
        {
            n11[i]=n[i];
        }
        f(i,m,l)
        {
            n12[i-m]=n[i];
        }
        num11=stoi(n11),num12=stoi(n12);
        ans1=num11+num12;
        f(i,0,p)
        {
            n21[i]=n[i];
        }
        f(i,p,l)
        {
            n22[i-p]=n[i];
        }
        num21=stoi(n21),num22=stoi(n22);
        ans2=num21+num22;
        if(ans1<ans2) cout<<ans1;
        else cout<<ans2;
    }
    return 0;
}
