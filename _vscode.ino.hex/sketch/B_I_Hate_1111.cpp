#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\B_I_Hate_1111.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        cout<<(((n/11)>=(n%11)*10)?"YES":"NO")<<endl;
    }
    return 0;
}