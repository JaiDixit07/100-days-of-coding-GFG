//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        // Your code here
        int count=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;         //value and frequency stored
        }
        for(auto it:mpp){         //iterate through mpp
            if(it.second > n/k){          //compare if freq(it.second) is greater tha n/k , if yes then count++
                count++;
            }
        }
        return count;        //at last return the count
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

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends