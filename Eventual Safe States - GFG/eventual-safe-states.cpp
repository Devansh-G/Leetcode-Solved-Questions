//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int &node, int &V, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        bool isCycle = false;
        for(auto adjacentNode : adj[node])
        {
            if(!vis[adjacentNode])
                isCycle = isCycle or dfs(adjacentNode, V, adj, vis, pathVis);
        
            else if(pathVis[adjacentNode])
                isCycle = true;
        }
        if(!isCycle)
            pathVis[node]=0;
        return isCycle;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        //This is DFS, for BFS, see leetcode
        vector<int> vis(V, 0), pathVis(V, 0);
        for(int i = 0; i<V ; i++)
        {
            if(!vis[i])
                dfs(i, V, adj, vis, pathVis);
        }
        vector<int> ans;
        for(int i=0 ; i<V; i++)
        {
            if(!pathVis[i])
                ans.push_back(i);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends