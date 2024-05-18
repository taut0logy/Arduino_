#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\lab_007.cpp"
#include<bits/stdc++.h>
using namespace std;
//the minimum number of constructos is 2.
class a
{
    char w;
    int x;
    double y;
    int z;
    public:
    a(int x=0,double y=0.0,char w='*')// for 2, 4, 5
    {
        this->w=w;
        this->x=x;
        this->y=y;
    }
    a(char w='*',int x=0,double y=0.0)// for 1, 3, 6
    {
        this->w=w;
        this->x=x;
        this->y=y;
    }
    void display()
    {
        cout<<w<<' '<<x<<' '<<y<<' '<<endl;
    }
};
int main()
{
    a a1('A',3,3.2);
    a1.display();
    a a2(2,3.4);
    a2.display();
    a a3('B',2);
    a3.display();
    a a4(2,3.3,'A');
    a4.display();
    a a5(2,3.4,2);
    a5.display();
    a a6('C');
    a6.display();
    return 0;
}