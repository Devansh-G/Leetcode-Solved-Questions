//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int &i, int &j, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i,j});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int dx = -1; dx<=1 ; dx++)
            {
                for(int dy = -1; dy<=1 ; dy++)
                {
                    int nx = x + dx, ny = y + dy;
                    if(nx>=0 and nx < n and ny >= 0 and ny < m and !vis[nx][ny] and grid[nx][ny] == '1')
                    {
                        q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis (n, vector<int> (m,0));
        for(int i = 0; i<n ;i++)
        {
            for(int j= 0 ; j<m ;j++)
            {
                if(!vis[i][j] and grid[i][j] == '1')
                {
                    bfs(i, j, vis, grid);
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends