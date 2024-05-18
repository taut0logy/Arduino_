#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\task_b2.cpp"
#include<bits/stdc++.h>
using namespace std;
double f(double x,double y)
{
    return 2*x+3*y*y;
}
void runga_kutta_4th_order(double x0,double y0,double xn,double h)
{
    vector<double> ans;
    ans.push_back(y0);
    for(double x=x0+h;x<=xn;x+=h)
    {
        double k1=h*f(x,y0);
        double k2=h*f(x+h/2,y0+k1/2);
        double k3=h*f(x+h/2,y0+k2/2);
        double k4=h*f(x+h,y0+k3);
        y0=y0+(k1+2*k2+2*k3+k4)/6;
        ans.push_back(y0);
    }
    for(int i=0;i<ans.size();i++)
        cout<<"x="<<x0+i*h<<", y="<<ans[i]<<endl;
}

void runga_kutta_3rd_order(double x0,double y0,double xn,double h)
{
    vector<double> ans;
    ans.push_back(y0);
    for(double x=x0+h;x<=xn;x+=h)
    {
        double k1=h*f(x,y0);
        double k2=h*f(x+h/2,y0+k1/2);
        double k3=h*f(x+h,y0-k1+2*k2);
        y0=y0+(k1+4*k2+k3)/6;
        ans.push_back(y0);
    }
    for(int i=0;i<ans.size();i++)
        cout<<"x="<<x0+i*h<<", y="<<ans[i]<<endl;
    ofstream fout;
    fout.open("runga_kutta_3rd_order.txt");
    fout<<"Runga Kutta 3rd order\n";
    fout<<"Equation: dy/dx=2x+3y^2\n";
    fout<<"x0="<<x0<<", y0=f(x0)="<<y0<<", xn="<<xn<<", h="<<h<<endl;
    for(int i=0;i<ans.size();i++)
        fout<<"x="<<x0+i*h<<", y="<<ans[i]<<endl;
    fout.close();

}

int main()
{
    double x0,y0,xn,h;
    cin>>x0>>y0>>xn>>h;
    runga_kutta_3rd_order(x0,y0,xn,h);
    

    return 0;
}

// .1 .1165 .2 .02 