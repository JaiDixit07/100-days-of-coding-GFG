//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int a[], int n)
   {
      for(int i=0;i<n/2;i++)
      {
          if(2*i+1 < n)          //2*i+1  → index of left child
          {
              if(a[i]<a[2*i+1])
               return false;
          }
          if(2*i+2 < n)          //2*i+2 → index of right child
          {
              if(a[i]<a[2*i+2])
               return false;
          }
      }
      return true;
   }
   };



//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends