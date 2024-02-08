//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {   
        sort(arr,arr+N);
        int i=0;
        int j=0;
        string str = "";
        while(i<=arr[0].size() && j<=arr[N-1].size()){
            if(arr[0][i]!=arr[N-1][j]){
                break;
            }
            else{
                str.push_back(arr[0][i]);
                i++;
                j++;
            }
        }
        if(str==""){
            return "-1";
        }
        return str;
            
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends