#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\string to int.cpp"
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
int stoint(string s)
{
     int l=s.length();
     int n=0;
     for(int i=0;i<l;i++)
     {
         n+=(s[i]-'0')*pow(10,l-1-i);
     }
     return n;
}
int main()
{
    string n;
    cin>>n;
    int n1=stoint(n);
    cout<<n1+5;
    return 0;
}

