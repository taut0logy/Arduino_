#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\002.c"
#include<iostream>
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
    int i,j,n;
    int s[n][n];
    s[0][0]=1,s[1][0]=1,s[1][1]=1;
    cin>>n;
    f(i,2,n)
    {
        s[i][0]=1;
        s[i][i]=1;
    }
    f(i,2,n)
    {
        f(j,2,n)
        {
            s[i][j]=s[i-1][j-1]+s[i-1][j];
            if(j==i)
            {
                break;
            }
        }
    }

    if(n==1)
    {
        cout<<"1";
    }
    else if (n==2)
    {
        cout"1"<<endl<<"1 1";
    }
    else
    {
        cout<<'1'<<endl<<"1 1"<<endl;
        f(i,2,n)
        {
            cout<<s[i][0]<<' ';
            f(j,1,n-1)
            {
                cout<<s[i][j]<<' ';
                if(j==i)
                {
                    break;
                }
            }
            cout<<"1"<<' '<<endl;
        }
    }
    return 0;
}

