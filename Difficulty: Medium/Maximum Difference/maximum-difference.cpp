//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
     vector<int> solve(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            while(st.size()>0 and arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.size()>0 and arr[i]>arr[st.top()]){
                ans[i]=arr[st.top()];
            }
            st.push(i);
        }
        return ans;
    }
    int findMaxDiff(vector<int> &arr) {
        vector<int>at=solve(arr);
        reverse(arr.begin(),arr.end());
        vector<int>gt=solve(arr);
        reverse(gt.begin(),gt.end());
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            ans=max(ans,abs(at[i]-gt[i]));
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends