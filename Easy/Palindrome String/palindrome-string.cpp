//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	bool checkpal(string &S,int start,int end )
{
    //Base case
    if(start>=end)
    return 1;
    //Not Match
    if(S[start]!=S[end])
    return 0;
    //Matched
    else
    return checkpal(S,start+1,end-1);
}
 
int isPalindrome(string S)
{
    // Your code goes here
    int n=S.length();
    return checkpal(S,0,n-1);
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
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends