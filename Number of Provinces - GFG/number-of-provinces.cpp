//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  // see number of provinces from leetcode
    void dfs(int i, int &V, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[i] = 1;
        for(int j=0 ; j <V; j++)
        {
            if(vis[j]==0 and adj[i][j]==1)
            {
                dfs(j, V, adj, vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int count = 0;
        vector<int> vis(V,0);
        for(int i = 0; i<V ; i++)
        {
            if(!vis[i])
            {
                count++;
                //cout<<i<<endl;
                dfs(i,V, adj, vis);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends