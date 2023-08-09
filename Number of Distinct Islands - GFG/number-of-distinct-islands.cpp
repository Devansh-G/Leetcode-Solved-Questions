//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<pair<int,int>> bfs(int &sx, int &sy, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        vector<pair<int, int>> v;
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = { 1, 0, -1, 0};
        int dy[] = { 0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({sx, sy});
        vis[sx][sy] = 1;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k =0 ;k<4 ; k++)
            {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx>=0 and nx<n and ny>=0 and ny< m and !vis[nx][ny] and grid[nx][ny]==1)
                {
                    q.push({nx,ny});
                    v.push_back({nx - sx, ny - sy});
                    vis[nx][ny] = 1;
                }
            }
        }
        return v;
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<vector<pair<int,int>>> s;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i = 0; i<n ; i++)
        {
            for(int j = 0; j<m ; j++)
            {
                if(!vis[i][j] and grid[i][j] == 1)
                    s.insert(bfs(i, j, vis, grid));
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends