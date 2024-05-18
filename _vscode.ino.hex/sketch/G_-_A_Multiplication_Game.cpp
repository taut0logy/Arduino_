#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\G_-_A_Multiplication_Game.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int x=1,i=1;
        while(x<n)
        {
            if(i&1) x*=9;
            else x*=2;
            i++;
        }
        if(i&1) cout<<"Ollie wins."<<endl;
        else cout<<"Stan wins."<<endl;
    }
    return 0;
}
