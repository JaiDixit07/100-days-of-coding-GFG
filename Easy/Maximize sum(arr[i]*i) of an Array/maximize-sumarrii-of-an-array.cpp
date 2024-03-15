//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int Maximize(int a[],int n)
    {
        // Complete the function
        std::sort(a, a + n);
        
        // Initialize the result variable
        long long result = 0;
        
        // Calculate the sum of arr[i]*i
        for (int i = 0; i < n; ++i) {
            result += (long long)a[i] * i;
        }
        
        // Return the result modulo 10^9 + 7
        return result % 1000000007;
    }
};

//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends