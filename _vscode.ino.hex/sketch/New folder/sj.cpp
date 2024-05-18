#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\New folder\\sj.cpp"
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t; cin >> t;
    for(int i = 1; i<=t; ++i){
        int a, b, c, k;
        ll ar[3];
        cin >> ar[0] >> ar[1] >> ar[2] >> k;
        sort(ar, ar+3);
        ll x = ar[2]-ar[0];
        ll y = ar[1]-ar[0];
        if((x%k==0)&&(y%k==0) && ((x+y)%3==0 &&(x+y)%k==0)){
            cout << "Case " << i << ": " << "Peaceful\n"; 
        }else{
            cout <<  "Case " << i << ": " << "Fight\n";
        }
    }
}