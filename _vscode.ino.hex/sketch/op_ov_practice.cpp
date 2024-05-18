#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\op_ov_practice.cpp"
#include <bits/stdc++.h>
using namespace std;
class frac
{
    int full, dec;

public:
    frac(int f = 0, int d = 0)
    {
        full = f;
        dec = d;
    }
    frac operator+(frac f)
    {
        frac c;
        c.full = full + f.full;
        c.dec = dec + f.dec;
        if (c.dec >= 100)
        {
            c.full++;
            c.dec -= 100;
        }
        return c;
    }
    frac operator++()
    {
        full++;
        return *this;
    }
    frac operator++(int)
    {
        frac temp = *this;
        full++;
        return temp;
    }
    friend ostream& operator<<(ostream &os,const  frac &f);
    friend istream& operator>>(istream &is,const frac &f);
};
ostream& operator<<(ostream &os,const frac &f)
{
    os << f.full << "." << f.dec;
    return os;
}
istream& operator>>(istream &is,const frac &f)
{
    is >> f.full >> f.dec;
    return is;
}
int main()
{
    frac a(1, 2), b(2, 3);
    frac c = a + b;
    cout << c << endl;
    cout << c++ << endl;
    cout << c << endl;
    cout << ++c << endl;
    cout << c << endl;
    return 0;
}