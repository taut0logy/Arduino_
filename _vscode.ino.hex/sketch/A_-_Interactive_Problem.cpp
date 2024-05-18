#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\A_-_Interactive_Problem.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i=1,x,y,ab,ac,bc;
    cin>>n;
    int a[n+1];
    for(i=1;i+2<=n-(n%3);i+=3)
    {
        cout<<"? "<<i<<" "<<i+1<<endl;
        cin>>ab;
        cout<<"? "<<i<<" "<<i+2<<endl;
        cin>>ac;
        cout<<"? "<<i+1<<" "<<i+2<<endl;
        cin>>bc;
        a[i+1]=(ab+bc-ac)/2;
        a[i]=ab-a[i+1];
        a[i+2]=ac-a[i];
    }
    if(n%3==1)
    {
        cout<<"? "<<n-1<<" "<<n<<endl;
        cin>>x;
        a[n]=x-a[n-1];
    }
    else if(n%3==2)
    {
        cout<<"? "<<n-2<<" "<<n-1<<endl;
        cin>>x;
        a[n-1]=x-a[n-2];
        cout<<"? "<<n-1<<" "<<n<<endl;
        cin>>y;
        a[n]=y-a[n-1];
    }
    cout<<"! ";
    for(i=1;i<=n;i++)
            cout<<a[i]<<" ";
    cout<<endl;
    return 0;

}