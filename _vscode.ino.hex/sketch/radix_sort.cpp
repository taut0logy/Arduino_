#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\radix_sort.cpp"
#include<bits/stdc++.h>
using namespace std;
void radixSort(int arr[], int n) 
{
    // Find the maximum number to know the number of digits
    int maxNum = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > maxNum) 
        {
            maxNum = arr[i];
        }
    }
    
    // Do counting sort for every digit
    for (int digit = 1; maxNum / digit > 0; digit *= 10) 
    {
        int count[10] = {0};
        
        // Count the number of occurrences of each digit
        for (int i = 0; i < n; i++) 
        {
            count[(arr[i] / digit) % 10]++;
        }
        
        // Calculate the cumulative count of each digit
        for (int i = 1; i < 10; i++) 
        {
            count[i] += count[i - 1];
        }
        
        // Build the sorted array by placing each element in the correct position
        int output[n];
        for (int i = n - 1; i >= 0; i--) 
        {
            output[count[(arr[i] / digit) % 10] - 1] = arr[i];
            count[(arr[i] / digit) % 10]--;
        }
        
        // Copy the sorted array back to the input array
        for (int i = 0; i < n; i++) 
        {
            arr[i] = output[i];
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n] ;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    radixSort(arr, n);
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    return 0;
}