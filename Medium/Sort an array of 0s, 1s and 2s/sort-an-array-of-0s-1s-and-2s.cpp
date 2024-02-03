//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int ptr1=0;
        int ptr2= n-1;
        
        int i=0;
        
        while(i<=ptr2){
            if(a[i]==0){
                swap(a[i++],a[ptr1++]);
            }
            else if(a[i]==2){
                swap(a[i],a[ptr2--]);
            }
            else{
                i++;
            }
            
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends