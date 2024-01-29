//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int N) {
        vector<int> repeating_numbers;

    // Use the array itself as a frequency map to save space
    for (int i = 0; i < N + 2; i++) {
        int index = abs(arr[i]) - 1;  // Map to the range 0 to N-1
        if (arr[index] < 0) {
            repeating_numbers.push_back(abs(arr[i]));
        } else {
            arr[index] = -arr[index];  // Mark as visited
        }
    }

    return repeating_numbers;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}

// } Driver Code Ends