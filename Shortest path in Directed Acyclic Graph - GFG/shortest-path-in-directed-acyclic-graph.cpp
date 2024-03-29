//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int &node, vector<vector<pair<int,int>>> &adj, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        for(auto adjacentNode : adj[node])
        {
            if(!vis[adjacentNode.first])
                dfs(adjacentNode.first , adj, vis, st);
        }
        st.push(node);
        return ;
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int, int>>> adj(N);
        for(int i = 0; i<M ; i++)
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            
        //For topological sort    
        stack<int> st;
        vector<int> vis(N,0);
        for(int i = 0;i<N; i++)
        {
            if(!vis[i])
                dfs(i,adj, vis, st);
        }
         
        vector<int> dist(N, 1e9);
        dist[0]=0;
       
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            for(auto it : adj[node])
            {
                int adjacentNode = it.first;
                int wt = it.second;
                if(dist[node] + wt < dist[adjacentNode])
                    dist[adjacentNode] =  dist[node] + wt;
            }
        }
        
        for(int i = 0 ;i< N;i++)
        {
            if(dist[i] == 1e9)
                dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends