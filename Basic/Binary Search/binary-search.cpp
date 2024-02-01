//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        int s=0;
        int end = n-1;
        
        int mid= s + ((end-s)/2);
        
        while(s<=end){
            if(arr[mid]==k){
                return mid;
            }
            
            else if(arr[mid]>k){
                end=mid-1;
            }
            
            else if(arr[mid]<k){
                s=mid+1;
            }
            
            mid= s + ((end-s)/2);
            
            
        
    }
    return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends