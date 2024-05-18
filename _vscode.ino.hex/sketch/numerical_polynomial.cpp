#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\numerical_polynomial.cpp"
#include<bits/stdc++.h>
using namespace std;


double funval(double a,double b,double c, double x)
{
    return a*x*x+b*x+c;
}

double newton_raphson(double a,double b,double c,double x,double prec,int itr)
{
    if(!itr)
    {
        cout<<"did not converge\n";
        return 1e9;
    }
    double fx=funval(a,b,c,x);
    double dfx=2*a*x+b;
    if(!dfx)
    {
        cout<<"division by 0\n";
        return 1e9;
    }
    double x1=x-fx/dfx;
    if(abs(x1-x)<prec)
    {
        cout<<"converged after "<<itr<<" iterations\n";
        return x1;
    }
    return newton_raphson(a,b,c,x1,prec,itr-1);
}

double secant(double a,double b,double c,double x1,double x2,double prec,int itr)
{
    if(!itr)
    {
        cout<<"did not converge\n";
        return 1e9;
    }
    double fx1=funval(a,b,c,x1);
    double fx2=funval(a,b,c,x2);
    if(!fx1-fx2)
    {
        cout<<"division by 0\n";
        return 1e9;
    }
    double x3=x2-fx2*(x2-x1)/(fx2-fx1);
    if(abs(x3-x2)<prec)
    {
        cout<<"converged after "<<itr<<" iterations\n";
        return x3;
    }
    return secant(a,b,c,x2,x3,prec,itr-1);
}

double bisection(double a,double b,double c,double x1,double x2,double prec,int itr)
{
    if(!itr)
    {
        cout<<"did not converge\n";
        return 1e9;
    }
    double fx1=funval(a,b,c,x1);
    double fx2=funval(a,b,c,x2);
    double x3=(x1+x2)/2;
    double fx3=funval(a,b,c,x3);
    if(!fx3)
    {
        cout<<"converged after "<<itr<<" iterations\n";
        return x3;
    }
    if(abs(x3-x2)<prec)
    {
        cout<<"converged after "<<itr<<" iterations\n";
        return x3;
    }
    if(fx1*fx3<0)
        return bisection(a,b,c,x1,x3,prec,itr-1);
    else
        return bisection(a,b,c,x3,x2,prec,itr-1);
}

double false_position(double a,double b,double c,double x1,double x2,double prec,int itr)
{
    if(!itr)
    {
        cout<<"did not converge\n";
        return 1e9;
    }
    double fx1=funval(a,b,c,x1);
    double fx2=funval(a,b,c,x2);
    double x3=(x1*fx2-x2*fx1)/(fx2-fx1);
    double fx3=funval(a,b,c,x3);
    if(!fx3)
    {
        cout<<"converged after "<<itr<<" iterations\n";
        return x3;
    }
    if(abs(x3-x2)<prec)
    {
        cout<<"converged after "<<itr<<" iterations\n";
        return x3;
    }
    if(fx1*fx3<0)
        return false_position(a,b,c,x1,x3,prec,itr-1);
    else
        return false_position(a,b,c,x3,x2,prec,itr-1);
}

double f(double x,double y)
{
    return x+y;
}

void runga_kutta(double x0,double y0,double xn,double h)
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


int main()
{
    double a=0,b=0,c=0,x1,x2;
    //if the coeddicient is 1, then it must be written as 1x^2 or 1x or 1
    cout<<"Enter equation (ax^2+bx+c=0):\n";
    char s[1000];
    scanf("%[^\n]%*c",s);
    sscanf(s,"%lfx^2%lfx%lf=0",&a,&b,&c);
    cout<<a<<' '<<b<<' '<<c<<endl;
    cout<<"Enter initial values of  x1 and x2:\n";
    cin>>x1>>x2;
    double x=secant(a,b,c,x1,x2,1e-6,100);
    if(x!=1e9) cout<<"Solution: "<<x<<endl;
    cout<<"Runga Kutta Method:\n";
    cout<<"Enter initial values of x0 and y0 and xn and h:\n";
    double x0,y0,xn,h;
    cin>>x0>>y0>>xn>>h;
    runga_kutta(x0,y0,xn,h);
    return 0;
}