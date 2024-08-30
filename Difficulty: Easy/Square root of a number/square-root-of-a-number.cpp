//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
          long long s=0,e=n;
        long long root=-1;;
       long long mid =(s+e)/2;
       
        while(s<=e){
            if(mid*mid>n){
                e=mid-1;
            }
            else if(mid*mid<n){
               root=mid;
               s=mid+1;
            }
            else if(mid*mid==n){
            root=mid;
            break;
            }
            mid =(s+e)/2;
        }
        return root;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends