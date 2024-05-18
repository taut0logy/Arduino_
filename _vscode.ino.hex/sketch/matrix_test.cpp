#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\matrix_test.cpp"
#include<bits/stdc++.h>
#include"Matrix.h"
using namespace std;
int main()
{
    Matrix<int> m(3,1),n(1,3);
    cin>>m>>n;
    Matrix<int> p=m+n;
    cout<<p;
}