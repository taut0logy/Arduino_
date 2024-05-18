#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\February_29.cpp"
#include <bits/stdc++.h>
using namespace std;
map<string,int>month;
void solve()
{
    string D1,M1,Y1,D2,M2,Y2;
    int m1,m2,d1,d2,y1,y2;
    cin>>M1>>D1>>Y1;
    D1.pop_back();
    cin>>M2>>D2>>Y2;
    D2.pop_back();
    m1=month[M1];
    m2=month[M2];
    d1=stoi(D1);
    d2=stoi(D2);
    y1=stoi(Y1);
    y2=stoi(Y2);
    //cout<<m1<<" "<<m2<<" "<<d1<<" "<<d2<<" "<<y1<<" "<<y2<<endl;
    if(m1>2) y1++;
    if(m2<2 || (m2==2 && d2<29)) y2--;
    int ans=y2/4-y2/100+y2/400-(y1-1)/4+(y1-1)/100-(y1-1)/400;
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Test,TT = 0;
    cin >> Test;
    month["January"]=1;
    month["February"]=2;
    month["March"]=3;
    month["April"]=4;
    month["May"]=5;
    month["June"]=6;
    month["July"]=7;
    month["August"]=8;
    month["September"]=9;
    month["October"]=10;
    month["November"]=11;
    month["December"]=12;
    while (TT++<Test)
    {
        cout<<"Case "<<TT<<": ";
        solve();
    }
    return 0;
}