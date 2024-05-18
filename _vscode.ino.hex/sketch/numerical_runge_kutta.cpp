#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\numerical_runge_kutta.cpp"
#include<bits/stdc++.h>
using namespace std;
double f(double x,double y){
    return x+y;
}
void rungeKutta(){
    float x0,y0,xn,h,k1,k2,k3,k4,delY;
    cin >> x0 >> y0 >> h >> xn;
    float x=x0;
    float y=y0;
    while(x < xn)
    {
        k1 = h * f(x, y);
        k2 = h * f(x + h / 2, y + k1 / 2);
        k3 = h * f(x + h / 2, y + k2 / 2);
        k4 = h * f(x + h, y + k3);
        delY = (k1 + (k2 + k3) * 2 + k4) / 6;
        x+=h;
        y+=delY;
        cout<<" when x = "<< x <<" y = " << y <<endl;
    }
}
int main(){
    rungeKutta();
    return 0;
}