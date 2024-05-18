#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\001.cpp"
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
    int h1,m1,h2,m2;
    cin>>h1>>m1>>h2>>m2;
    if(h1==0 && m1==0)
    {
        cout<<"Takahashi";
    }
    else if(h1<h2)
    {

        cout<<"Takahashi";

    }
    else if(h1==h2)
    {
        if(m1<=m2)
        {
            cout<<"Takahashi";
        }
        else
        {
            cout<<"Aoki";
        }
    }
    else if(h1>h2)
    {
        cout<<"Aoki";
    }
    return 0;

}

