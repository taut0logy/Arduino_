#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\matrix_friend_func.cpp"
#include<bits/stdc++.h>
using namespace std;

class matrix
{
    int row;
    int col;
    int **arr;
    public:
    matrix(int r,int c)
    {
        row=r;
        col=c;
        arr=new int*[row];
        for(int i=0;i<row;i++)
        {
            arr[i]=new int[col];
        }
    }
    void input()
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cin>>arr[i][j];
            }
        }
    }
    void display()
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    friend matrix operator+(matrix &m1,matrix &m2);
    friend matrix add(matrix &m1,matrix &m2);
};

matrix operator+(matrix &m1,matrix &m2)
{
    matrix temp(m1.row,m1.col);
    for(int i=0;i<m1.row;i++)
    {
        for(int j=0;j<m1.col;j++)
        {
            temp.arr[i][j]=m1.arr[i][j]+m2.arr[i][j];
        }
    }
    return temp;
}

matrix add(matrix &m1,matrix &m2)
{
    matrix temp(m1.row,m1.col);
    for(int i=0;i<m1.row;i++)
    {
        for(int j=0;j<m1.col;j++)
        {
            temp.arr[i][j]=m1.arr[i][j]+m2.arr[i][j];
        }
    }
    return temp;
}

int main()
{
    int r,c;
    cin>>r>>c;
    matrix m1(r,c);
    matrix m2(r,c);
    m1.input();
    m2.input();
    matrix m3=m1+m2;
    m3.display();
    return 0;
}