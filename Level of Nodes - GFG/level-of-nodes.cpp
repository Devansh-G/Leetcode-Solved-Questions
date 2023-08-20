//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    vector<int> dist(V, 1e9);
	    queue<pair<int, int>> q;
	    q.push({0,0});
	    dist[0] = 0;
	    while(!q.empty())
	    {
	        int level = q.front().first;
	        int node = q.front().second;
	        if(node == X)
	            return level;
	        q.pop();
	        for(auto &adjacentNode : adj[node])
	        {
	            if(dist[adjacentNode] > level + 1)
	            {
	                dist[adjacentNode] = level + 1;
	                q.push({level + 1, adjacentNode});
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends