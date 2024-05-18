#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\numerical_lab05.cpp"
#include <iostream>
#include <vector>

using namespace std;



void luDecomposition(const vector<vector<double>> &A, vector<vector<double>> &L, vector<vector<double>> &U)
{
    int n = A.size();


    for (int i = 0; i < n; ++i)
    {
        L[i][i] = 1.0;

        for (int j = i; j < n; ++j)
        {
            double sum = 0.0;

            for (int k = 0; k < i; ++k)
            {
                sum += L[i][k] * U[k][j];
            }

            U[i][j] = A[i][j] - sum;
        }

        for (int j = i + 1; j < n; ++j)
        {
            double sum = 0.0;

            for (int k = 0; k < i; ++k)
            {
                sum += L[j][k] * U[k][i];
            }

            L[j][i] = (A[j][i] - sum) / U[i][i];
        }
    }
}

vector<double> solveLinearEquation(const vector<vector<double>> &A, const vector<double> &b)
{
    int n = A.size();
    vector<vector<double>> L(n, vector<double>(n, 0.0)), U(n, vector<double>(n, 0.0));
    luDecomposition(A, L, U);
    cout<<"L Matrix: \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;i<n;j++) cout<<L[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
    cout<<"U Matrix: \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;i<n;j++) cout<<U[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
    vector<double> y(n, 0.0);
    for (int i = 0; i < n; ++i)
    {
        double sum = 0.0;
        for (int j = 0; j < i; ++j)
        {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i][i];
    }

    vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; --i)
    {
        double sum = 0.0;
        for (int j = i + 1; j < n; ++j)
        {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }
    return x;
}


int main()
{
    int n;
    cout<<"ENter Number of unknowns:\n";
    cin >> n;
    vector<vector<double>> A;
    vector<double> b(n);
    for (int i = 0; i < n; i++)
    {
        vector<double> temp(3);
        scanf("%lfx%lfy%lfz=%lf", &temp[0], &temp[1], &temp[2], &b[i]);
        cout<<temp[0]<<' '<<temp[1]<<' '<<temp[2]<<' '<<b[i]<<endl;
        A.push_back(temp);
    }

    vector<double> x = solveLinearEquation(A, b);

    cout << "Solution x:" << endl;
    for (int i = 0; i < x.size(); ++i)
    {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    return 0;
}
