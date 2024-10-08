//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        // Your code here
        int res=arr[0];
        
        if(arr[high]>arr[low]) return res;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            res=min(res,arr[mid]);
            
            if(arr[mid]<arr[high]) //minimum will be on the left side 
            {
                high=mid-1;
            }
            else  //minimum will be on the right side 
            {
                low=mid+1;
            }
        }
        return res;
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
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}
// } Driver Code Ends