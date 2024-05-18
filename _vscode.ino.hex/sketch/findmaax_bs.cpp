#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\findmaax_bs.cpp"
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    int s=0;
	    int e=n-1;
	    int mid=s+(e-s)/2;
	    while(s<=e)
	    {
	        if(arr[mid-1]<arr[mid+1] && arr[mid]>arr[mid+1])
	        {
	            return arr[mid];
	        }
	        else if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1])
	        {
	            s=mid+1;
	        }
	        else
	        {
	            e=mid-1;
	        }
	        mid=s+(e-s)/2;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends