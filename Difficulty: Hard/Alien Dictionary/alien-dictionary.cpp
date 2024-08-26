//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        // code here
        //build graph
        vector<int> vis(26, 0);
        vector<unordered_set<int>> adj(26);
        
        for (int i = 0; i < n - 1; i++) {
            int sz = min(dict[i].size(), dict[i + 1].size());
            for (int j = 0; j < sz; j++) {
                if (dict[i][j] != dict[i + 1][j]) {
                    int u = dict[i][j] - 'a';
                    int v = dict[i + 1][j] - 'a';
                    if (adj[u].find(v) == adj[u].end()) {
                        adj[u].insert(v);
                    }
                    break;
                }
            }
        }
        // Perform topological sorting using BFS
        vector<int> indegree(26, 0);
        for (int i = 0; i < 26; i++) {
            for (int j : adj[i]) {
                indegree[j]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        string order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order += 'a' + node;
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return order;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends