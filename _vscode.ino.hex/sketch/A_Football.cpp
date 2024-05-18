#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_Football.cpp"
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    map<string,int> m;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        m[s]++;
    }
    vector<pair<int,string>> v;
    for(auto x:m) 
        v.push_back({x.second,x.first});
    sort(v.rbegin(),v.rend());
    cout<<v[0].second;
    return 0;
}