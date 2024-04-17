//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        if(a.size() !=b.size()) return false;
        
        vector<int>s1(26,-1);
        vector<int>s2(26,-1);
        for(auto ch:a){
            s1[ch-'a']++;
        }
        for(auto ch: b){
            s2[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(s1[i] !=s2[i]) return false;
        }
        return true;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends