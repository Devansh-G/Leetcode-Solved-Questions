//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int &node, vector<int> adj[], vector<int> &color)
    {
        for(auto adjacentNode : adj[node])
        {
            if(color[adjacentNode] == -1)
            {
                color[adjacentNode] = !color[node];
                if(dfs(adjacentNode, adj, color)==false)
                    return false;
            }
            else if(color[adjacentNode] == color[node])
                return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    // for BFS, see Bipartite graph on leetcode
        vector<int> color(V,-1);
        /* -1 means not visited
            0 means first color
            1 means second color
        */
        for(int i = 0 ;i<V;i++)
        {
            if(color[i] == -1)
            {
                color [i] = 0;
                if(dfs(i, adj, color) == false)
                    return false;
            }
        }
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends