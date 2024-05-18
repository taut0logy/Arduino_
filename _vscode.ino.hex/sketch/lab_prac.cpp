#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\lab_prac.cpp"
#include<bits/stdc++.h>
using namespace std;
class shape
{
    protected:
    double height;
    double width;
    public:
    shape(double h,double w)
    {
        height=h;
        width=w;
    }
    virtual void display()
    {
        cout<<"Base class display"<<endl;
    }
    double area()
    {
        return height*width;
    }
};
class rectangle:public shape
{
    public:
    rectangle(double h,double w):shape(h,w){}
    void display()
    {
        cout<<"Area of rectangle is "<<area()<<endl;
    }
};
class triangle:public shape
{
    public:
    triangle(double h,double w):shape(h,w)
    {
    }
    double area()
    {
        return (height*width)/2;
    }
    void display()
    {
        cout<<"Area of triangle is "<<area()<<endl;
    }
};
int main()
{
    //shape *s;
    rectangle r(13,21);
    triangle t(13,21);
    r.display();
    t.display();
    /* s=&r;
    s->display();
    s=&t;
    s->display(); */
    return 0;
}