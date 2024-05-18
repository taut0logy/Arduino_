#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\oop01.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class complexnumber
{
private:
    int real;
    float imaginary;
public:
    complexnumber()
    {
        real = 0;
        imaginary = 0;
    }
    complexnumber(int r, float i)
    {
        real = r;
        imaginary = i;
    }
    void display()
    {
        cout << "the number is: " << real << " + " << imaginary << "i" << endl;
    }
    int getreal()
    {
        return real;
    }
    float getimaginary()
    {
        return imaginary;
    }
};
complexnumber add(complexnumber n1, complexnumber n2)
{
    int r;
    float i;
    r = n1.getreal() + n2.getreal();
    i = n1.getimaginary() + n2.getimaginary();
    complexnumber temp(r, i);
    return temp;
}
int main()
{
    complexnumber c1(5, 4), c2(-4, 7), c3;
    c1.display();
    c2.display();
    cout << "addition:" << endl;
    c3 = add(c1, c2);
    c3.display();
    return 0;
}
