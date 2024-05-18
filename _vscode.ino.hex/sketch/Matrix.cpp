#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Matrix.cpp"
//#include"Matrix.h"
#include<bits/stdc++.h>
using namespace std;
template<typename T>
Matrix<T>::Matrix(int row,int col):row(row),col(col)
{
    arr=new T*[row];
    for(int i=0;i<row;i++)
    {
        arr[i]=new T[col];
    }
}
template<typename T>
Matrix<T>::~Matrix()
{
    for(int i=0;i<row;i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
}
template<typename T>
void Matrix<T>::deepcopy(const Matrix &m)
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
template<typename T>
Matrix<T>::Matrix(const Matrix &m)
{
    deepcopy(m);
}
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix &m)
{
    if(this!=&m)
    {
        deepcopy(m);
    }
    return *this;
}
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &m)
{
    int r=max(row,m.row);
    int c=max(col,m.col);
    Matrix<T> temp(r,c);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i<row && j<col && i<m.row && j<m.col)
            {
                temp.arr[i][j]=arr[i][j]+m.arr[i][j];
            }
            else if(i<row && j<col)
            {
                temp.arr[i][j]=arr[i][j];
            }
            else if(i<m.row && j<m.col)
            {
                temp.arr[i][j]=m.arr[i][j];
            }
        }
    }
    return temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix &m)
{
    int r=max(row,m.row);
    int c=max(col,m.col);
    Matrix<T> temp(r,c);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i<row && j<col && i<m.row && j<m.col)
            {
                temp.arr[i][j]=arr[i][j]-m.arr[i][j];
            }
            else if(i<row && j<col)
            {
                temp.arr[i][j]=arr[i][j];
            }
            else if(i<m.row && j<m.col)
            {
                temp.arr[i][j]=m.arr[i][j];
            }
        }
    }
    return temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &m)
{
    try
    {
        if(col!=m.row)
        {
            throw "Invalid Multiplication";
        }
    }
    catch(const char *s)
    {
        cout<<s<<endl;
        exit(0);
    }
    Matrix<T> temp(row,m.col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<m.col;j++)
        {
            temp.arr[i][j]=0;
            for(int k=0;k<col;k++)
            {
                temp.arr[i][j]+=arr[i][k]*m.arr[k][j];
            }
        }
    }
    return temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator+(const T &x)
{
    Matrix<T> temp(row,col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            temp.arr[i][j]=arr[i][j]+x;
        }
    }
    return temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator*(const T &x)
{
    Matrix<T> temp(row,col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            temp.arr[i][j]=arr[i][j]*x;
        }
    }
    return temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator-(const T &x)
{
    Matrix<T> temp(row,col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            temp.arr[i][j]=arr[i][j]-x;
        }
    }
    return temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator/(const T &x)
{
    Matrix<T> temp(row,col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            temp.arr[i][j]=arr[i][j]/x;
        }
    }
    return temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator%(const T &x)
{
    Matrix<T> temp(row,col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            temp.arr[i][j]=arr[i][j]%x;
        }
    }
    return temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator^(const T &x)
{
    Matrix<T> temp(row,col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            temp.arr[i][j]=pow(arr[i][j],x);
        }
    }
    return temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator++()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            arr[i][j]++;
        }
    }
    return *this;
}
template<typename T>
Matrix<T> Matrix<T>::operator++(int)
{
    Matrix<T> temp(row,col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            temp.arr[i][j]=arr[i][j]++;
        }
    }
    return temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator--()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            arr[i][j]--;
        }
    }
    return *this;
}
template<typename T>
Matrix<T> Matrix<T>::operator--(int)
{
    Matrix<T> temp(row,col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            temp.arr[i][j]=arr[i][j]--;
        }
    }
    return temp;
}
template<typename T>
Matrix<T> Matrix<T>::operator+=(const Matrix &m)
{
    *this=*this+m;
    return *this;
}
template<typename T>
Matrix<T> Matrix<T>::operator-=(const Matrix &m)
{
    *this=*this-m;
    return *this;
}
template<typename T>
Matrix<T> Matrix<T>::operator*=(const Matrix &m)
{
    *this=*this*m;
    return *this;
}
template<typename T>
Matrix<T> Matrix<T>::operator+=(const T &x)
{
    *this=*this+x;
    return *this;
}
template<typename T>
Matrix<T> Matrix<T>::operator-=(const T &x)
{
    *this=*this-x;
    return *this;
}
template<typename T>
Matrix<T> Matrix<T>::operator*=(const T &x)
{
    *this=*this*x;
    return *this;
}
template<typename T>
Matrix<T> Matrix<T>::operator/=(const T &x)
{
    *this=*this/x;
    return *this;
}
template<typename T>
Matrix<T> Matrix<T>::operator%=(const T &x)
{
    *this=*this%x;
    return *this;
}
template<typename T>
Matrix<T> Matrix<T>::operator^=(const T &x)
{
    *this=*this^x;
    return *this;
}
template<typename T>
bool Matrix<T>::operator==(const Matrix &m) const
{
    if(row!=m.row || col!=m.col)
    {
        return false;
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(arr[i][j]!=m.arr[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
template<typename T>
bool Matrix<T>::operator!=(const Matrix &m) const
{
    if(row!=m.row || col!=m.col)
    {
        return true;
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(arr[i][j]!=m.arr[i][j])
            {
                return true;
            }
        }
    }
    return false;
}
template<typename T>
Matrix<T> Matrix<T>::transpose()
{
    Matrix<T> temp(col,row);
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
        {
            temp.arr[i][j]=arr[j][i];
        }
    }
    return temp;
}
template<typename T>
T Matrix<T>::det()
{
    try
    {
        if(row!=col)
        {
            throw "Not a square matrix";
        }
        if(row==1)
        {
            return arr[0][0];
        }
        if(row==2)
        {
            return arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
        }
        T d=0;
        for(int i=0;i<row;i++)
        {
            Matrix<T> temp(row-1,col-1);
            for(int j=1;j<row;j++)
            {
                for(int k=0;k<col;k++)
                {
                    if(k<i)
                    {
                        temp.arr[j-1][k]=arr[j][k];
                    }
                    else if(k>i)
                    {
                        temp.arr[j-1][k-1]=arr[j][k];
                    }
                }
            }
            d+=pow(-1,i)*arr[0][i]*temp.det();
        }
        return d;
    }
    catch(const char *s)
    {
        cout<<s<<endl;
    }
}
template<typename T>
Matrix<T> Matrix<T>::inverse()
{
    try
    {
        if(row!=col)
        {
            throw "Not a square matrix";
        }
        Matrix<T> temp(row,col);
        T d=det();
        if(d==0)
        {
            throw "Inverse does not exist";
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                Matrix<T> temp1(row-1,col-1);
                for(int k=0;k<row;k++)
                {
                    for(int l=0;l<col;l++)
                    {
                        if(k<i && l<j)
                        {
                            temp1.arr[k][l]=arr[k][l];
                        }
                        else if(k<i && l>j)
                        {
                            temp1.arr[k][l-1]=arr[k][l];
                        }
                        else if(k>i && l<j)
                        {
                            temp1.arr[k-1][l]=arr[k][l];
                        }
                        else if(k>i && l>j)
                        {
                            temp1.arr[k-1][l-1]=arr[k][l];
                        }
                    }
                }
                temp.arr[i][j]=pow(-1,i+j)*temp1.det()/d;
            }
        }
        return temp.transpose();
    }
    catch(const char *s)
    {
        cout<<s<<endl;
    }
}
template<typename T>
Matrix<T> Matrix<T>::adjoint()
{
    try
    {
        if(row!=col)
        {
            throw "Not a square matrix";
        }
        Matrix<T> temp(row,col);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                Matrix<T> temp1(row-1,col-1);
                for(int k=0;k<row;k++)
                {
                    for(int l=0;l<col;l++)
                    {
                        if(k<i && l<j)
                        {
                            temp1.arr[k][l]=arr[k][l];
                        }
                        else if(k<i && l>j)
                        {
                            temp1.arr[k][l-1]=arr[k][l];
                        }
                        else if(k>i && l<j)
                        {
                            temp1.arr[k-1][l]=arr[k][l];
                        }
                        else if(k>i && l>j)
                        {
                            temp1.arr[k-1][l-1]=arr[k][l];
                        }
                    }
                }
                temp.arr[i][j]=pow(-1,i+j)*temp1.det();
            }
        }
        return temp.transpose();
    }
    catch(const char *s)
    {
        cout<<s<<endl;
    }
}
template<typename T>
T& Matrix<T>::operator()(const int i,const int j)
{
    try
    {
        if(i-1<0 || i-1>=row || j-1<0 || j-1>=col)
        {
            throw "Index out of bounds";
        }
        return arr[i-1][j-1];
    }
    catch(const char *s)
    {
        cout<<s<<endl;
    }
}
template<typename T>
T Matrix<T>::trace()
{
    try
    {
        if(row!=col)
        {
            throw "Not a square matrix";
        }
        T t=0;
        for(int i=0;i<row;i++)
        {
            t+=arr[i][i];
        }
        return t;
    }
    catch(const char *s)
    {
        cout<<s<<endl;
    }
}
template<typename T>
T Matrix<T>::minor(int r,int c)
{
    try
    {
        if(row!=col)
        {
            throw "Not a square matrix";
        }
        if(r<0 || r>=row || c<0 || c>=col)
        {
            throw "Index out of bounds";
        }
        Matrix<T> temp(row-1,col-1);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i<r && j<c)
                {
                    temp.arr[i][j]=arr[i][j];
                }
                else if(i<r && j>c)
                {
                    temp.arr[i][j-1]=arr[i][j];
                }
                else if(i>r && j<c)
                {
                    temp.arr[i-1][j]=arr[i][j];
                }
                else if(i>r && j>c)
                {
                    temp.arr[i-1][j-1]=arr[i][j];
                }
            }
        }
        return temp.det();
    }
    catch(const char *s)
    {
        cout<<s<<endl;
    }
}
template<typename T>
T Matrix<T>::cofactor(int r,int c)
{
    try
    {
        if(row!=col)
        {
            throw "Not a square matrix";
        }
        if(r<0 || r>=row || c<0 || c>=col)
        {
            throw "Index out of bounds";
        }
        return pow(-1,r+c)*minor(r,c);
    }
    catch(const char *s)
    {
        cout<<s<<endl;
    }
}
template<typename T>
ostream& operator<<(ostream &out,const Matrix<T> &m)
{
    for(int i=0;i<m.row;i++)
    {
        for(int j=0;j<m.col;j++)
        {
            out<<m.arr[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}
template<typename T>
istream& operator>>(istream &in,Matrix<T> &m)
{
    for(int i=0;i<m.row;i++)
    {
        for(int j=0;j<m.col;j++)
        {
            in>>m.arr[i][j];
        }
    }
    return in;
}
template<typename T>
Matrix<T> pow(const Matrix<T> &m,const int n)
{
    try
    {
        if(m.row!=m.col)
        {
            throw "Not a square matrix";
        }
        if(n==0)
        {
            Matrix<T> temp(m.row,m.col);
            for(int i=0;i<m.row;i++)
            {
                temp.arr[i][i]=1;
            }
            return temp;
        }
        if(n==1)
        {
            return m;
        }
        if(n<0)
        {
            return pow(m.inverse(),-n);
        }
        Matrix<T> temp(m.row,m.col);
        temp=pow(m,n/2);
        if(n%2==0)
        {
            return temp*temp;
        }
        else
        {
            return m*temp*temp;
        }
    }
    catch(const char *s)
    {
        cout<<s<<endl;
    }
}