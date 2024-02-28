//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        int num=0;
        int ten=1;
        for(int i=s.length()-1;i>=0 and i>=(s.length()-3);i--)
        {
            num+=((int(s[i]))*ten);
            ten*=10;
        }
        if(num%8)
        return -1;
        else
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends