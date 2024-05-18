#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\numm.cpp"
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
const double epsilon=1e-7;
vector<vector<int>>A(3,vector<int>(3,0));
vector<int>b(3,0);
vector<vector<double>>L(3,vector<double>(3,0.0));
vector<vector<double>>U(3,vector<double>(3,0.0));
vector<double>x(3,0.0);
vector<double>y(3,0.0);
int row=0;
void extractCoefficientsAndPopulate(string equation) {
    vector<int>n;
    string currentNumber;
    for(char c:equation){
        if(isdigit(c) || (c == '-'&&currentNumber.empty())){
            currentNumber+=c;
        }
        else{
            if(!currentNumber.empty()){
                n.push_back(stoi(currentNumber));
                currentNumber.clear();
            }
        }
    }

    if(!currentNumber.empty()){
       n.push_back(stoi(currentNumber));
    }
    A[row].resize(n.size()-1);
    for (int i=0;i<3;i++) {
        A[row][i]=n[i];
    }
    b[row]=n[3];
    row++;

}
void luFactorization() {
    int n=A.size();
    for(int i=0;i<n;i++){
        // Upper triangular matrix U
        for(int k=i;k<n;k++){
            double sum=0.0;
            for(int j=0;j<i;j++){
                sum+=L[i][j]*U[j][k];
            }
            U[i][k]=A[i][k]-sum;
        }

        // Lower triangular matrix L
        for(int k=i;k<n;k++){
            if(i==k){
                L[i][i]=1.0;
            }
            else{
                double sum=0.0;
                for(int j=0;j<i;j++){
                    sum+=L[k][j]*U[j][i];
                }
                L[k][i]=(A[k][i]-sum)/U[i][i];
            }
        }
    }
}
void forwardSubstitution(){
    int n=L.size();
    for(int i=0;i<n;i++){
        y[i]=b[i];
        for(int j=0;j<i;j++){
            y[i]-=L[i][j]*y[j];
        }
    }
}
void backwardSubstitution(){
    int n=U.size();
    for(int i=n-1;i>=0;i--){
        x[i]=y[i];
        for(int j=i+1;j<n;j++){
            x[i]-=U[i][j]*x[j];
        }
        x[i]/=U[i][i];
    }
}

int main(){
    string s1="1x+3y-0z=12";
    string s2="1x+4y+5z=14";
    string s3="1x+6y+7z=18";
    extractCoefficientsAndPopulate(s1);
    extractCoefficientsAndPopulate(s2);
    extractCoefficientsAndPopulate(s3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<A[i][j]<<' ';
        }
        cout<<endl;
    }
    luFactorization();
    forwardSubstitution();
    backwardSubstitution();
    cout<<"Solution vector x:"<<endl;
    for(int i=0;i<3;i++){
        cout<<"x"<<i+1<<" = "<<x[i]<<endl;
    }
    return 0;
}
