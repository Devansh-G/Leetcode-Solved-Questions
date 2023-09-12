//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int &node, vector<int> &visited, vector<vector<int>> &adj)
    {
        visited[node]=1;
        for(auto &adjacentNode: adj[node])
        {
            if(!visited[adjacentNode])
            {
                dfs(adjacentNode, visited, adj);
            }
        }
    }
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        if(edge.size()<n-1)
            return -1;
        int ans=0;
        vector<int> visited(n,0);
        vector<vector<int>> adj(n);
        for(auto &it : edge)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i, visited,adj);
                ans++;
            }
        }
        return ans-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends