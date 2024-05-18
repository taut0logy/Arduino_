#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Untitled3.cpp"
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
    string n;
    cin>>n;
    int m[10]={0},l=n.size();
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<l;j++)
        {
            if(n[j]-'0'==m[i])
            {
                m[i]++;
            }
        }
    }
    for(int i=0;i<10;i++)
    {
        cout<<m[i]<<' ';
    }
    cout<<endl;
    int max=*max_element(m,m+10);
    for(int i=0;i<10;i++)
    {
        if(m[i]==max)
        {
            cout<<i+5;
            break;
        }
    }
    return 0;
}