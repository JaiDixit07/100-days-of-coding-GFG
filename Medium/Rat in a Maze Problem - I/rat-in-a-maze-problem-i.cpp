//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
        void solve(int i,int j,vector<vector<int>>&m,int n,string s,vector<string>&v){
            if(i>=n || i<0 ||j>=n || j<0 || m[i][j]==0){
                return;
            }
            else if((i==n-1) && (j==n-1)){
                v.push_back(s);
                return;
            }
            
            m[i][j]=0;
            solve(i+1,j,m,n,s+"D",v);
            solve(i-1,j,m,n,s+"U",v);
            solve(i,j+1,m,n,s+"R",v);
            solve(i,j-1,m,n,s+"L",v);
            m[i][j]=1;
        }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> v ;
        string s= "";
        
        if(m[0][0]==0 || m[n-1][n-1]==0){
            v.push_back("-1");
        }
        else{
            solve(0,0,m,n,s,v);
            
        }
        return v;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends