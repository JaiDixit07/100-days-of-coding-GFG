//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long mx = 1 , mn = 1;
        long long ans = INT_MIN;
        
        for(int i=0 ; i<n ;i++){
            if(arr[i]<0)
                swap(mx , mn);
            
            long long num = (long long)arr[i];
            
            mx = max(num , mx*num);
            mn = min(num , mn*num);
            
            ans= max(ans , mx);
            
        }
        
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends