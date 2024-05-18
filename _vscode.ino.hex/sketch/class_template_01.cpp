#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\class_template_01.cpp"
#include <bits/stdc++.h>
using namespace std;
class exam
{
public:
    double a;
    exam(int x = 0)
    {
        a = x;
    }
    exam operator+(exam x)
    {
        exam res(a + x.a);
        return res;
    }
    int operator/(int x)
    {
        return a / x;
    }
};
class complex
{
public:
    double a, b;
    complex(double x = 0, double y = 0)
    {
        a = x;
        b = y;
    }
    complex operator+(complex x)
    {
        complex res(a + x.a, b + x.b);
        return res;
    }
    complex operator/(int x)
    {
        complex res(a / x, b / x);
        return res;
    }
};
template <class T>
T average(T arr[], int n)
{
    T sum = T();
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    return sum / n;
}
int main()
{
    exam arr[6];
    for (int i = 0; i < 6; i++)
    {
        arr[i].a = i + 1;
    }
    exam x = average<exam>(arr, 6);
    cout << x.a << endl;
    return 0;
}