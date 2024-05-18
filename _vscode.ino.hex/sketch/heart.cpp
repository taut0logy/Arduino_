#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\heart.cpp"
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int rows=10, cols=10;

    for (int i = rows / 2; i <= rows; i += 2)
    {
        for (int j = 1; j < rows - i; j += 2)
        {
            cout << " ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        for (int j = 1; j <= rows - i; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    for (int i = rows; i >= 1; i--) 
    {
        for (int j = i; j < rows; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= (i * 2) - 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}