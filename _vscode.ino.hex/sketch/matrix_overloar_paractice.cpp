#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\matrix_overloar_paractice.cpp"
#include <bits/stdc++.h>
using namespace std;
class matrix
{
private:
    int row, col;
    int **arr;
    class matrix_row
    {
    private:
        int *arr;
        int col;
    public:
        matrix_row(int *a, int c)
        {
            arr = a;
            col = c;
        }
        int &operator[](int i)
        {
            if (i < 0 || i >= col)
            {
                cout << "Invalid column index" << endl;
                exit(0);
            }
            return arr[i];
        }
    };

public:
    matrix(int r, int c)
    {
        row = r;
        col = c;
        arr = new int *[row];
        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[col];
        }
    }
    matrix_row operator[](int i)
    {
        if (i < 0 || i >= row)
        {
            cout << "Invalid row index" << endl;
            exit(0);
        }
        return matrix_row(arr[i], col);
    }
    matrix operator+(matrix m)
    {
        matrix temp(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                temp.arr[i][j] = arr[i][j] + m.arr[i][j];
            }
        }
        return temp;
    }
    matrix operator*(matrix m)
    {
        matrix temp(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                temp.arr[i][j] = arr[i][j] * m.arr[i][j];
            }
        }
        return temp;
    }
    friend ostream &operator<<(ostream &os, matrix m);
    friend istream &operator>>(istream &is, matrix &m);
};
ostream &operator<<(ostream &os, matrix m)
{
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            os << m.arr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}
istream &operator>>(istream &is, matrix &m)
{
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            is >> m.arr[i][j];
        }
    }
    return is;
}
int main()
{
    matrix a(3, 3);
    cin>>a;
    cout << a << endl;
    cout << a[1][2] << endl;
}