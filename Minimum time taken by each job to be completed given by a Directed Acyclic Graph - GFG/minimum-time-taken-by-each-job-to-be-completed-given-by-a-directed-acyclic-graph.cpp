//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            // code here          
            vector<int> indegrees(n+1,0);
            vector<vector<int>> adj(n+1);
            for(auto &edge : edges)
            {
                adj[edge[0]].push_back(edge[1]);
                indegrees[edge[1]]++;
            }
            int t = 0;
            vector<int> ans(n+1,-1);
            queue<int> q;
            for(int i=1;i<=n;i++)
            {
                if(indegrees[i] == 0)
                    q.push(i);
            }
            int len = 0;
            //for(int i = 1; i<=n ;i++)
            while(!q.empty())
            {
                if(len==0)
                {
                    len = q.size();
                    t++;
                }
                len--;
                int node = q.front();
                q.pop();
                ans[node] = t;
                for(auto &adjacentNode : adj[node])
                {
                    indegrees[adjacentNode]--;
                    if(indegrees[adjacentNode]==0)
                        q.push(adjacentNode);
                }
            }
            ans.erase(ans.begin());
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends