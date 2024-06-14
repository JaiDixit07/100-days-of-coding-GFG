//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string>st;
        string res;
        for(int i=pre_exp.length()-1;i>=0;i--){
            char c=pre_exp[i];
            if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
                st.push(string(1,c));
            }
            else{
                string operand1=st.top();
                st.pop();
                string operand2=st.top();
                st.pop();
                res='('+operand1+c+operand2+')';
                st.push(res);
                
            }
        }
        string ans
        return st.top();
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends