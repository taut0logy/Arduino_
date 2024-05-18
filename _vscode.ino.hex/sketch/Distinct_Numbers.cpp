#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Distinct_Numbers.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    set<int> s;
    for(int i=0;i<n;i++)
   {
        int x;
        scanf("%d",&x);
        s.insert(x);
   }
    printf("%d",s.size());
    return 0;
}