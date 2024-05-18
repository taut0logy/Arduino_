#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Y_-_Lost_Numbers.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[6]={4,8,15,16,23,42},a,b;
    pair<int,int> ab,ac;
    map<int,pair<int,int>> m;
    for(int i=0;i<6;i++)
    {
        for(int j=i+1;j<6;j++)
        {
            m[arr[i]*arr[j]]={arr[i],arr[j]};
        }
    }
    int ans[6];
    printf("? 1 2\n");
    fflush(stdout);
    scanf("%d",&a);
    printf("? 1 3\n");
    fflush(stdout);
    scanf("%d",&b);
    ab=m[a],ac=m[b];
    if(ab.first==ac.first)
    {
        ans[0]=ab.first;
        ans[1]=ab.second;
        ans[2]=ac.second;
    }
    else if(ab.first==ac.second)
    {
        ans[0]=ab.first;
        ans[1]=ab.second;
        ans[2]=ac.first;
    }
    else if(ab.second==ac.first)
    {
        ans[0]=ab.second;
        ans[1]=ab.first;
        ans[2]=ac.second;
    }
    else if(ab.second==ac.second)
    {
        ans[0]=ab.second;
        ans[1]=ab.first;
        ans[2]=ac.first;
    }
    printf("? 4 5\n");
    fflush(stdout);
    scanf("%d",&a);
    printf("? 4 6\n");
    fflush(stdout);
    scanf("%d",&b);
    ab=m[a],ac=m[b];
    if(ab.first==ac.first)
    {
        ans[3]=ab.first;
        ans[4]=ab.second;
        ans[5]=ac.second;
    }
    else if(ab.first==ac.second)
    {
        ans[3]=ab.first;
        ans[4]=ab.second;
        ans[5]=ac.first;
    }
    else if(ab.second==ac.first)
    {
        ans[3]=ab.second;
        ans[4]=ab.first;
        ans[5]=ac.second;
    }
    else if(ab.second==ac.second)
    {
        ans[3]=ab.second;
        ans[4]=ab.first;
        ans[5]=ac.first;
    }
    printf("!");
    for(int i=0;i<6;i++) printf(" %d",ans[i]);
    fflush(stdout);
    return 0;
}