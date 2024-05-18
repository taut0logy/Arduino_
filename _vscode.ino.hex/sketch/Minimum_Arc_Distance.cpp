#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Minimum_Arc_Distance.cpp"
#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<": ";
        double ox,oy,ax,ay,bx,by;
        cin>>ox>>oy>>ax>>ay>>bx>>by;
        double r=sqrt((ox-ax)*(ox-ax)+(oy-ay)*(oy-ay));
        double ab=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
        double theta=acos((2*r*r-ab*ab)/(2*r*r));
        double arc_acb=r*theta;
        cout<<fixed<<setprecision(10)<<arc_acb<<endl;
    }
    return 0;
}