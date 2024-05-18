#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\New folder (2)\\hanium.cpp"
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5];
    stack<int> s;
    int k;
    cin >> k;
    s.push(k);
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        s.push(arr[i]);
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}