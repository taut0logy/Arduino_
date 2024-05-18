#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\b1.cpp"
#include<bits/stdc++.h>
using namespace std;
double funval(double a,double b, double c, double d, double e,double x)
{
    return a*x*x*x*x+b*x*x*x+c*x*x+d*x+e;
}

double ddx(double a,double b, double c, double d, double e,double x)
{
    return 4*a*x*x*x+3*b*x*x+2*c*x+d;
}
double newton_raphson(double a,double b,double c,double d,double e,double x,double prec,int itr)
{
    if(!itr)
    {
        cout<<"did not converge\n";
        return 1e9;
    }
    double fx=funval(a,b,c,d,e,x);
    double dfx=ddx(a,b,c,d,e,x);
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
    return newton_raphson(a,b,c,d,e,x1,prec,itr-1);
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
    double a=0,b=0,c=0,d=0,e=0,x0=0;
    //if the coefficient is 1, then it must be written as 1x^2 or 1x or 1
    //if the coefficient is 0, then it must be written as 0x^2 or 0x or 0
    cout<<"Enter equation (ax^4+bx^3+cx^2+dx+e=0):\n";
    char s[1000];
    scanf("%[^\n]%*c",s);
    sscanf(s,"%lfx^4%lfx^3%lfx^2%lfx%lf",&a,&b,&c,&d,&e);
    cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<endl;
    cout<<"Enter initial values of  x0:\n";
    cin>>x0;
    double x=newton_raphson(a,b,c,d,e,x0,1e-6,100);
    if(x!=1e9) cout<<"Solution: "<<x<<endl;
    cout<<"Runga Kutta Method:\n";
    cout<<"Enter initial values of x0 and y0 and xn and h:\n";
    double x0,y0,xn,h;
    cin>>x0>>y0>>xn>>h;
    runga_kutta(x0,y0,xn,h);
    return 0;
}
//1x^4-1x^3+0x^2+1x+0