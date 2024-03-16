//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> negative;
    vector<int> positive;
    
    for (int i=0; i<n; i++){
        if (arr[i] >= 0)
            positive.push_back(arr[i]);
        
        else
            negative.push_back(arr[i]);
    }
    
    int pos = 0, neg = 0, i =0;
    while (i < n){
        
        if (pos != positive.size()){
            arr[i] = positive[pos];
            i++;
            pos++;
        }
        
        if (neg != negative.size()){
            arr[i] = negative[neg];
            i++;
            neg++;
        }
    }
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
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends