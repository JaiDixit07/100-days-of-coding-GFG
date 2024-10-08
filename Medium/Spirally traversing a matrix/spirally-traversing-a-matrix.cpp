//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
         vector<int>res;
        
        // if the matrix empty or if r or c value os given 0 then return res
        if( matrix.empty() || r == 0 || c == 0){
            return res;
        }
        
        // initialize four variables top, bottom, left, right 
        
        int top = 0;
        int left =0;
        int bottom = r-1;
        int right = c-1;
        
        
        
        while( top <= bottom && left <= right){
            
            // traverse right 
            for(int i=left ; i<= right; i++){
                res.push_back(matrix[top][i]);
            }
            // After we have completely traversed one row, 
            // increase the value of the top so that it points to next row 
            top++;
            
            // traverse down
            for(int i= top; i<= bottom; i++){
                res.push_back(matrix[i][right]);
            }
            // After we have traversed the last column decrement the value of the right,
            // so that it points to column before that column
            right--;
            
            // traverse left
            
            // while traversing from right to left, we need to check whether
            // top is less than equal to bottom or not 
            // because there may be the case when top is not less than bottom but the left is less than right
            // so in that case we dont need to print anything
            if( left <= right && top <= bottom){
                for(int i= right; i>= left; i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            // traverse up
            // Similarly while goint from bottom to top, we need to check 
            // whether left is less than equal to right or not 
            if( top <= bottom && left <= right){
                for(int i= bottom; i>= top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends