#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\op_ov_matrix.cpp"
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
    void input()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> arr[i][j];
            }
        }
    }
    void display()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
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
    matrix operator-(matrix m)
    {
        matrix temp(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                temp.arr[i][j] = arr[i][j] - m.arr[i][j];
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
    matrix operator/(matrix m)
    {
        matrix temp(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                temp.arr[i][j] = arr[i][j] / m.arr[i][j];
            }
        }
        return temp;
    }
    int det()
    {
        int d = 0;
        if (row == 2)
        {
            d = arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
        }
        else
        {
            for (int i = 0; i < col; i++)
            {
                matrix temp(row - 1, col - 1);
                int r = 0, c = 0;
                for (int j = 0; j < row; j++)
                {
                    for (int k = 0; k < col; k++)
                    {
                        if (j != 0 && k != i)
                        {
                            temp.arr[r][c] = arr[j][k];
                            c++;
                            if (c == col - 1)
                            {
                                r++;
                                c = 0;
                            }
                        }
                    }
                }
                d += pow(-1, i) * arr[0][i] * temp.det();
            }
        }
        return d;
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
    matrix a(3, 3), b(3, 3);
    a.input();
    b.input();
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << a.det() << endl;
}