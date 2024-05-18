#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\IP_Checking.cpp"
#include <bits/stdc++.h>
using namespace std;

// Checks if the ip addresses are the same
bool isSame(string binaryIP, string decimalIP) {
    // TODO: Complete this method
    int a[4],b[4];
    int i=0,j=0;
    while(i<4)
    {
        int x=0;
        while(j<binaryIP.size()&&binaryIP[j]!='.')
        {
            x=x*2+binaryIP[j]-'0';
            j++;
        }
        a[i]=x;
        i++;
        j++;
    }
    i=0,j=0;
    while(i<4)
    {
        int x=0;
        while(j<decimalIP.size()&&decimalIP[j]!='.')
        {
            x=x*10+decimalIP[j]-'0';
            j++;
        }
        b[i]=x;
        i++;
        j++;
    }
    for(int i=0;i<4;i++)
    {
        if(a[i]!=b[i]) return false;
    }
    return true;
}

int main() {
    // Read the number of test cases
    int cases;
    cin >> cases;

    // Iterate over the test cases
    for (int caseno = 1; caseno <= cases; ++caseno) {
        // Read the IP addresses
        string decimalIP, binaryIP;
        cin >> decimalIP >> binaryIP;

        // Check if they are the asme
        string res = isSame(binaryIP, decimalIP) ? "Yes" : "No";

        // Print the result
        cout << "Case " << caseno << ": " << res << endl;
    }

    return 0;
}
