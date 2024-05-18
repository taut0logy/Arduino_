#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\ddees.cpp"
/* Seisu-ya, a store specializing in non-negative integers, sells N non-negative integers. The i-th integer is Ai and has a utility of Bi. There may be multiple equal integers with different utilities.Takahashi will buy some integers in this store. He can buy a combination of integers whose bitwise OR is less than or equal to K. He wants the sum of utilities of purchased integers to be as large as possible.Find the maximum possible sum of utilities of purchased integers.
Input
N K
A1 B1
A2 B2
:
AN BN
Output
The maximum possible sum of utilities of purchased integers.
Constraints
1≤N≤100000
0≤K≤109
0≤Ai,Bi≤109
All values in input are integers.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string reverseWords(string s)
    {
        reverse(s.begin(),s.end());
        int n=s.size();
        int i=0,j;
        while(i<n)
        {
            int j=i;
            while(j<n && s[j]!=' ')
            {
                j++;
            }
            reverse(s.begin()+i,s.begin()+j);
            i=j+1;
        }
        //eliminate extra spaces
        i=0;
        j=0;
        while(j<n)
        {
            while(j<n && s[j]==' ')
            {
                j++;
            }
            while(j<n && s[j]!=' ')
            {
                s[i++]=s[j++];
            }
            while(j<n && s[j]==' ')
            {
                j++;
            }
            if(j<n)
            {
                s[i++]=' ';
            }
        }
        s.erase(s.begin()+i,s.end());
        return s;
    }
int main()
{
    int n,k;
    cin >> n >> k;
    vector<pair<ll,ll>> v(n);
    for(int i=0;i<n;i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end());
    ll ans=0;
    ll sum=0;
    priority_queue<ll> pq;
    for(int i=0;i<n;i++)
    {
        sum+=v[i].second;
        pq.push(v[i].second);
        if(pq.size()>k)
        {
            sum-=pq.top();
            pq.pop();
        }
        ans=max(ans,sum*v[i].first);
    }
    cout << ans << endl;
    
    return 0;
}