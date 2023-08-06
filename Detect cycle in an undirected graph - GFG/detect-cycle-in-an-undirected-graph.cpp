//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    // bool bfs(int i, int &V, vector<int> &vis, vector<int> adj[])
    // {
    //     vis[i] = 1;
    //     queue<pair<int,int>> q;
    //     q.push({i,-1});
        
    //     while(!q.empty())
    //     {
    //         int node = q.front().first;
    //         int parent = q.front().second;
    //         q.pop();
    //         for(auto adjacentNode : adj[node])
    //         {
    //             if(!vis[adjacentNode])
    //             {
    //                 vis[adjacentNode]=1;
    //                 q.push({adjacentNode,node});
    //             }
    //             else if(adjacentNode!=parent)
    //                 return true;
    //         }
    //     }
    //     return false;
    // }
    
    //USING DFS
    bool dfs(int node, int parent, vector<int> &vis, vector<int> adj[])
    {
        vis[node] =1;
        for(auto adjacentNode : adj[node])
        {
            if(!vis[adjacentNode])
            {
                if(dfs(adjacentNode, node, vis, adj))
                    return true;
            }
            else if(adjacentNode != parent)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        
        // USING BFS
        // vector<int> vis (V,0);
        
        // for(int i = 0; i < V ; i++)
        // {
        //     if(!vis[i])
        //     {
        //         if( bfs(i, V, vis, adj) == true)
        //             return true;
        //     }
        // }
        // return false;
        
        //USING DFS
        vector<int> vis(V,0);
        for(int i=0 ;i<V; i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,vis,adj))
                    return true;
            }
        }
        return false;
    };
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends