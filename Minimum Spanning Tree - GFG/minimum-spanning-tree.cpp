//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int findPar(int u, vector<int> &par)
    {
        if(u==par[u])
            return u;
        return par[u] = findPar(par[u], par);
	}
	void Union(int u, int v, vector<int> &size, vector<int> &par)
	{
        int ulp_u = findPar(u, par);
        int ulp_v = findPar(v, par);
        if(ulp_u == ulp_v)
            return;
        if(size[ulp_u] < size[ulp_v])
        {
            par[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            par[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //Prims ALGO
        // priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int , int>>> pq;
        // // we will need parent if we want to store the MST, for length we just need node and weight
        // pq.push({0,0});
        // vector<int> vis(V,0);
        // int sum = 0;
        
        // while(!pq.empty())
        // {
        //     int wt = pq.top().first;
        //     int node = pq.top().second;
        //     pq.pop();
        //     if(vis[node])
        //         continue;
        //     vis[node] = 1;
        //     sum += wt;
        //     for(auto it : adj[node])
        //     {
        //         pq.push({it[1], it[0]});
        //     }
        // }
        // return sum;
        
        //KRUSKALS ALGO
        //vector<pair<int, pair<int, int>>>v;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int,int>>>, greater<pair<int, pair<int,int>>> > pq;
        for(int i = 0; i<V ; i++)
        {
            for(auto it : adj[i])
            {
                // v.push_back({it[1], {i, it[0]}});
                pq.push({it[1], {i, it[0]}});
            }
        }
        //sort(v.begin(), v.end());
        
        vector<int> size(V, 1), par(V);
        for(int i=0;i<V;i++)
        {
            par[i] = i;
        }
        int ans = 0;
        
        //for(auto it : v)
        while(!pq.empty())
        {
            // int wt = it.first;
            // int u = it.second.first;
            // int v = it.second.second;
            
            int wt = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            
            if(findPar(u,par) != findPar(v, par))
            {
                Union(u, v, size, par);
                ans+=wt;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends