#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\s.cpp"
  // https://codeforces.com/contest/109/problem/A

   #include<bits/stdc++.h>

   using namespace std;


int main()
{
    int n,i,j;
    cin>>n;
    int bsev=0;
    int bfr=0;

    while(n>=0)
    {
        if(n%7==0)
        {
            bsev=n/7;
            n=0;
            break;
        }
        bfr++;
        n=n-4;
    }
    if(n==0)
    {
        while(bfr--) cout<<"4";
        while(bsev--) cout<<"7";
    }
    else cout<<"-1"<<endl;
}