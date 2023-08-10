//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    //DFS
    // bool dfs(int &node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[])
    // {
    //     vis[node] = 1;
    //     pathVis[node] = 1;
    //     for(auto adjacentNode : adj[node])
    //     {
    //         if(!vis[adjacentNode])
    //         {
    //             if(dfs(adjacentNode, vis, pathVis, adj)==true)
    //                 return true;
    //         }
    //         else if(pathVis[adjacentNode])
    //             return true;
    //     }
    //     pathVis[node] = 0;
    //     return false;
    // }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // DFS
        // vector<int> vis(V,0);
        // vector<int> pathVis(V,0);
        // for(int i = 0 ;i<V;i++)
        // {
        //     if(!vis[i])
        //     {
        //         if(dfs(i, vis, pathVis, adj)==true)
        //             return true;
        //     }
        // }
        // return false;
        
        //Using BFS or Kahn's Algo
        vector<int> indegrees(V,0);
	   for(int i=0 ;i< V; i++)
	   {
	       for(auto node : adj[i])
	           indegrees[node]++;
	   }
	   
	    int count=0;
	    queue<int> q;
	    for(int i =0 ; i<V ; i++)
	    {
	        if(indegrees[i] == 0)
	            q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for(auto adjacentNode : adj[node])
            {
                indegrees[adjacentNode]--;
                if(indegrees[adjacentNode]==0)
                    q.push(adjacentNode);
            }
        }
        
        if(count == V)
            return false;
        return true;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends