#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\oop_c2_02.cpp"
#include<bits/stdc++.h>
using namespace std;
class _2D
{
protected:
    double x,y;
    public:
    _2D(int a=0,int b=0)
    {
        x=a;
        y=b;
    }
    const istream& operator>>(const istream& in)
    {
        in>>x>>y;
        return in;
    }
    const ostream& operator<<(const ostream& out)
    {
        out<<"("<<x<<","<<y<<")";
        return out;
    }
    double get_dis_distance(_2D a,_2D b)
    {
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    }
};
class _3D:public _2D
{
protected:
    double z;
public:
    _3D(int a=0,int b=0,int c=0) : _2D(a, b)
    {
        z=c;
    }
    const istream& operator>>(const istream& in)
    {
        in>>x>>y>>z;
        return in;
    }
    const ostream& operator<<(const ostream& out)
    {
        out<<"("<<x<<","<<y<<","<<z<<")";
        return out;
    }
};
