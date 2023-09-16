//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int> (m,1e9));
        priority_queue<pair<int,pair<int, int>> , vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        while(!pq.empty())
        {
            int x = pq.top().second.first, y= pq.top().second.second, distance = pq.top().first;
            if(x==n-1 and y==m-1)
                return distance;
            //cout<<x<<" "<<y<<endl;
            pq.pop();
            for(int i = 0; i<4 ; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx>=0 and nx<n and ny>=0 and ny<m and dist[nx][ny]>max(abs(heights[nx][ny] - heights[x][y]), dist[x][y]))
                {
                    dist[nx][ny] = max(abs(heights[nx][ny] - heights[x][y]), dist[x][y]);
                    pq.push({dist[nx][ny],{nx,ny}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends