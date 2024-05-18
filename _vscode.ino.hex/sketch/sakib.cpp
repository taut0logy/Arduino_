#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\sakib.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double fun(double a, double b, double c, double x)
{
    return a * x * x + b * x + c;
}
double false_position(double a, double b, double c, double x1, double x2, int n, double prec)
{
    if (n == 0)
    {
        cout << "Didn't converge." << endl;
        return 1e9;
    }
    double f1 = fun(a, b, c, x1);
    double f2 = fun(a, b, c, x2);
    if (f2 - f1 == 0)
    {
        cout << "Division by zero error." << endl;
        return 1e9;
    }
    double x3 = x2 - (f2 * (x2 - x1)) / (f2 - f1);
    double f3 = fun(a, b, c, x3);

    cout << "Iteration " << n << ": x1 = " << x1 << ", x2 = " << x2 << ", x3 = " << x3 << ", f(x3) = " << f3 << endl;

    if (abs(f3) < prec)
    {
        cout << "Converged after " << 100 - n + 1 << " iterations\n";
        return x3;
    }
    if (f1 * f3 < 0)
        return false_position(a, b, c, x1, x3, n - 1, prec);
    else
        return false_position(a, b, c, x3, x2, n - 1, prec);
}
int main()
{
    double a, b, c;
    scanf("%lfx^2%lfx%lf=0", &a, &b, &c);
    cout << "Equation: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;

    double x1, x2;
    cin >> x1 >> x2;

    double ans = false_position(a, b, c, x1, x2, 100, 0.001);

    if (ans != 1e9)
        cout << "Root found at x = " << ans << endl;
    else
        cout << "Root not found within the specified tolerance." << endl;

    return 0;
}
/*1x^2-4x-10=0*/