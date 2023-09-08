//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &it : edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1,1e9), prev(n+1,0);
        for(int i = 0 ; i<=n ; i++)
            prev[i] = i;
            
        pq.push({0,1});
        dist[1] = 0;
        while(!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();
            for(auto &it : adj[node])
            {
                if(dist[node] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[node] + it.second;
                    prev[it.first] = node;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        if(dist[n]>=1e9)
            return {-1};
        vector<int> path;
        path.push_back(n);
        while(path.back()!=1)
        {
            path.push_back(prev[path.back()]);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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