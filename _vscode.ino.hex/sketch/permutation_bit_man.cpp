#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\permutation_bit_man.cpp"
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int total=1<<n;
    for(int i=0;i<total;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
                cout<<s[j];
        }
        cout<<endl;
    }
}