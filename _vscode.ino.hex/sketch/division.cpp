#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\division.cpp"
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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n>=1900)
        {
            cout<<"Division 1"<<endl;
        }
        else if(n<1900 && n>=1600)
        {
            cout<<"Division 2"<<endl;
        }
        else if(n<1600 && n>=1400)
        {
            cout<<"Division 3"<<endl;
        }
        else
        {
            cout<<"Division 4"<<endl;
        }
    }
    return 0;
}

