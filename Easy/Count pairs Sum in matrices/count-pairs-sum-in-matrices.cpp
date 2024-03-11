//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    //Initialize the ans 
	    int ans = 0;
	    
	   // Initialize the variables to traverse the matrices, will start from 1st Element of 1st Matrix and last Element of second matrix
	    int row1=0, col1 =0, row2 =n-1, col2 =n-1;
	    
	   // This is very similar to traverse two 1D Arrays, with a bit of change in the Implmentation.
	    while(row1<n and row2>=0) {
	        int val = mat1[row1][col1] + mat2[row2][col2];
	        
	       // If the val is equal to x, then go to the next elements, Increment Col1 and Decrement Col2
	        if(val == x) {
	            ans++;
	            col1++;
	            col2--;
	        }
	        
	       // If the val is greater than x, that means val needs to be decreased, so decrease col2.
	        if(val > x) 
	          col2--;
	          
	       //   If the val is less than x, that means val needs to be Increased, so Increase col1.
	        if(val < x)
	          col1++;
	         
	       //  If col1, goes out of matrix, then we should go to next row
	         if(col1 == n) {
	           row1++;
	           col1 = 0;
	         }
	         
	           //If col2, goes out of matrix, then we should go to prev row last element
	         if(col2 == -1) {
	           row2--;
	           col2 = n-1;
	         }
	        
	    }
	    return ans;
	}
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends