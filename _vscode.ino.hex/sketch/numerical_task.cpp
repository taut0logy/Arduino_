#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\numerical_task.cpp"
#include <bits/stdc++.h>
using namespace std;

vector<int> extract(string s)
{
    vector<int> coeff(100, 0);
    double esp1, esp2;
    for (int i = 0; i < s.size(); i++)
    {

        int pow;
        double coe;
        string p = "";
        string c = "";
        if (s[i] == '=')
        {
            i++;
        }

        while (s[i] != '=' && s[i] != 'x' && s[i] != '\0')
        {
            c += s[i];
            i++;
        }

        if (s[i] == '=')
            esp1 = stoi(c);
        else if (s[i] == '\0')
            esp2 = stoi(c);

        else
        {
            if (c == "" || c == "+" || c == "-")
                c += '1';
            coe = stoi(c);
            i++;
            if (s[i] != '^')
            {
                coeff[1] = coe;
            }
            else
            {
                i++;
                while (s[i] != '+' && s[i] != '-' && s[i] != '=')
                    p += s[i++];
                pow = stoi(p);
                coeff[pow] = coe;
            }
        }
        i--;
    }
    coeff[0] = esp1 - esp2;
}

double f(vector<int> coeff,double x)
{
    double ans=0;
    for(int i=coeff.size()-1;i>=0;i--)
    {
        ans+=coeff[i]*pow(x,i);
    }
    return ans;
}

double df(vector<int> coeff,double x)
{
    double ans=0;
    for(int i=coeff.size()-1;i>=1;i--)
    {
        ans+=coeff[i]*i*pow(x,i-1);
    }
    return ans;
}

double newton_raphson(vector<int> coeff,double x,double prec,int itr)
{
    for(int i=0;i<itr;i++)
    {
        double fx=f(coeff,x);
        double dfx=df(coeff,x);
        if(!dfx)
        {
            cout<<"did not converge\n";
            return 1e9;
        }
        double x1=x-fx/dfx;
        if(abs(x1-x)<prec)
        {
            cout<<"converged after "<<i<<" iterations\n";
            return x1;
        }
        x=x1;
    }
    cout<<"did not converge\n";
    return 1e9;
}

double bisection(vector<int> coeff,double x1,double x2,double prec,int itr)
{
    for(int i=0;i<itr;i++)
    {
        double fx1=f(coeff,x1);
        double fx2=f(coeff,x2);
        if(fx1*fx2>0)
        {
            cout<<"did not converge\n";
            return 1e9;
        }
        double x3=(x1+x2)/2;
        double fx3=f(coeff,x3);
        if(abs(fx3)<prec)
        {
            cout<<"converged after "<<i<<" iterations\n";
            return x3;
        }
        if(fx1*fx3<0)
        {
            x2=x3;
        }
        else
        {
            x1=x3;
        }
    }
    cout<<"did not converge\n";
    return 1e9;
}

int main()
{

    vector<int> coeff;
    vector<int> coeff;
    string s;
    while(s!="=")
    {
        int n;
        cin>>n>>s;
        coeff.push_back(n);
    }
    for(int i=0;i<coeff.size();i++)
    {
        cout<<coeff[i]<<" ";
    }
    cout<<endl;
    double x,prec;
    int itr;
    cin>>x>>prec>>itr;
    double ans=newton_raphson(coeff,x,prec,itr);
    if(ans!=1e9)
        cout<<ans<<endl;
    return 0;
}