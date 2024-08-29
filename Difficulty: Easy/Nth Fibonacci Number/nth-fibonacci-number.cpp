//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        int baseF = 1;
        int baseS = 1;
        const int mod = 1e9 + 7;
        for (int i = 3; i <= n; ++i) {
            int tmp = baseF + baseS;
            baseF = baseS;
            baseS = tmp % mod;
        }
        return baseS;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends