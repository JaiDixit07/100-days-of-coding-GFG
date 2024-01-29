//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
    int currentSum = 0;
        int start = 0;
        int end = -1;

        for (int i = 0; i < n; i++) {
            currentSum += arr[i];

            while (currentSum > s && start < i) {
                currentSum -= arr[start];
                start++;
            }

            if (currentSum == s) {
                end = i;
                break; // Found the first subarray, stop searching
            }
        }

        vector<int> result;
        if (end == -1) {
            result.push_back(-1);
        } else {
            result.push_back(start + 1); // 1-based indexing
            result.push_back(end + 1);
        }

        return result;
    }
    
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends