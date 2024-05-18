#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_Mainak_and_Interesting_Sequence.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        if(s<n)
        {
            cout<<"No"<<endl;
            continue;
        }
        if(n%2)
        {
            cout<<"Yes"<<endl;
            for(int i=1;i<n;i++)
            {
                cout<<1<<' ';
            }
            cout<<s-n+1<<endl;
        }
        else
        {
            int x=s-n+2;
            if(x<0 || x%2)
            {
                cout<<"No"<<endl;
                continue;
            }
            cout<<"Yes"<<endl;
            for(int i=1;i<n-1;i++)
            {
                cout<<1<<' ';
            }
            cout<<x/2<<' '<<x/2<<endl;
        }
    }
    return 0;
}