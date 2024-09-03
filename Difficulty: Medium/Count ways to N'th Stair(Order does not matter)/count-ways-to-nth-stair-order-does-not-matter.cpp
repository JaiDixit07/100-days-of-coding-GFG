//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthStair(int n){
		    int prev2 = 1;
		    int prev = 1;
		    for(int i=2;i<=n;i++){
		        int curi = 1 + min(prev, prev2);
		        prev2 = prev;
		        prev = curi;
		    }
		    return prev;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends