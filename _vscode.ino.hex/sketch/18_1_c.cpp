#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\18_1_c.cpp"
#include <bits/stdc++.h>
using namespace std;

class DB;

class DM
{
public:
    double m;
    double cm;
    DM()
    {
        this->m = 0;
        this->cm = 0;
    }
    DM(int a, int b)
    {
        this->m = a;
        this->cm = b;
    }
    void show()
    {
        cout << m << " m " << cm << " cm " << endl;
    }
    friend DM add(DM a, DB b);
    friend DB add(DB a, DM b);
};

class DB
{
public:
    double ft;
    double inch;
    DB()
    {
        this->ft = 0;
        this->inch = 0;
    }
    DB(int x, int y)
    {
        this->ft = x;
        this->inch = y;
    }
    void show()
    {
        cout << ft << " feet " << inch << " inches " << endl;
    }
    friend DB add(DB a, DM b);
    friend DM add(DM a, DB b);
};

DM add(DM a, DB b)
{
    DM ans;
    ans.m = a.m + b.ft * (0.12*2.54);
    ans.cm = a.cm + b.inch * 2.54 + (ans.m-floor(ans.m))*100;
    ans.m = ans.m + floor(ans.cm / 100.0);
    ans.cm = fmod(ans.cm, 100.0);
    ans.m=floor(ans.m);
    return ans;
}

DB add(DB a, DM b)
{
    DB res;
    res.ft = a.ft + b.m * 39 / 12;
    res.inch = a.inch + b.cm * 0.39 + (res.ft - floor(res.ft)) * 12;
    res.ft = res.ft + floor(res.inch / 12.0);
    res.inch = fmod(res.inch, 12.0);
    res.ft=floor(res.ft);
    return res;
}

int main()
{
    DM x(5, 89);
    DB y(5, 11);
    DM z = add(x, y);
    DB p = add(y, x);
    z.show();
    p.show();
    return 0;
}