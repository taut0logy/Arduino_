#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Matrix_oop.cpp"
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Matrix
{
    int row,col;
    T **arr;
    public:
    Matrix(int row,int col):row(row),col(col)
    {
        arr=new T*[row];
        for(int i=0;i<row;i++)
        {
            arr[i]=new T[col];
        }
    }
    ~Matrix()
    {
        for(int i=0;i<row;i++)
        {
            delete [] arr[i];
        }
        delete [] arr;
    }
    void deepcopy(const Matrix &m)
    {
        for(int i=0;i<row;i++)
        {
            delete [] arr[i];
        }
        delete [] arr;
        row=m.row;
        col=m.col;
        arr=new T*[row];
        for(int i=0;i<row;i++)
        {
            arr[i]=new T[col];
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                arr[i][j]=m.arr[i][j];
            }
        }
    }
    Matrix(const Matrix &m)
    {
        deepcopy(m);
    }
    Matrix& operator=(const Matrix &m)
    {
        if(this!=&m)
        {
            deepcopy(m);
        }
        return *this;
    }
    Matrix operator+(Matrix &m)
    {
        Matrix res(max(row,m.row),max(col,m.col));
        for(int i=0;i<max(row,m.row);i++)
        {
            for(int j=0;j<max(col,m.col);j++)
            {
                if(i<row && j<col && i<m.row && j<m.col)
                {
                    res.arr[i][j]=arr[i][j]+m.arr[i][j];
                }
                else if(i<row && j<col)
                {
                    res.arr[i][j]=arr[i][j];
                }
                else if(i<m.row && j<m.col)
                {
                    res.arr[i][j]=m.arr[i][j];
                }
                else
                {
                    res.arr[i][j]=0;
                }
            }
        }
        return res;
    }
    Matrix operator*(Matrix &m)
    {
        try
        {
            if(col!=m.row)
            {
                throw "Invalid dimensions";
            }
        }
        catch(const char *s)
        {
            cout << s << endl;
            throw;
            return Matrix(0,0);
        }
        catch(...)
        {
            cout << "Some error occured" << endl;
            return Matrix(0,0);
        }
        Matrix res(row,m.col);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<m.col;j++)
            {
                res.arr[i][j]=0;
                for(int k=0;k<col;k++)
                {
                    res.arr[i][j]+=arr[i][k]*m.arr[k][j];
                }
            }
        }
        return res;
    }
    template<typename U>
    friend ostream& operator<<(ostream &os,Matrix<U> &m);
    template<typename U>
    friend istream& operator>>(istream &is,Matrix<U> &m);
};
template<typename T>
ostream& operator<<(ostream &os,Matrix<T> &m)
{
    for(int i=0;i<m.row;i++)
    {
        for(int j=0;j<m.col;j++)
        {
            os << m.arr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}
template<typename T>
istream& operator>>(istream &is,Matrix<T> &m)
{
    for(int i=0;i<m.row;i++)
    {
        for(int j=0;j<m.col;j++)
        {
            is >> m.arr[i][j];
        }
    }
    return is;
}
int main()
{
    Matrix<int> m1(2,2);
    Matrix<int> m2(3,2);
    cin >> m1;
    cin >> m2;
    cout << m1;
    cout << m2;
    Matrix<int> m3=m1+m2;
    cout << m3 << endl;
    Matrix<int> m4=m1*m2;
    cout << m4 << endl;
    return 0;
}