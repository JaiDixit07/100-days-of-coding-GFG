//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    long long merge(long long arr[], long long temp[], long long left, long long mid, long long right){
        long long inversionCount = 0, i = left, j = mid, k = left;
        
        while((i <= mid-1) && j <= right){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
                inversionCount += mid - i;
            }
        }
        
        while(i <= mid-1) temp[k++] = arr[i++];
        while(j <= right) temp[k++] = arr[j++];
        
        for(int i=left;i<=right;i++) arr[i] = temp[i];
        
        return inversionCount;
    }
  
    long long merge_sort(long long arr[], long long temp[], long long left, long long right){
        long long inversionCount = 0;
        
        if(left < right){
            long long mid = (left + right) / 2;
            inversionCount += merge_sort(arr, temp, left, mid);
            inversionCount += merge_sort(arr, temp, mid+1, right);
            
            inversionCount += merge(arr, temp, left, mid+1, right);
        }
        return inversionCount;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        return merge_sort(arr, temp, 0, N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends