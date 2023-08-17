//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> matrix,vis(n, vector<int> (m, 0));
        matrix = grid;
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        
        queue<pair<int, int>> q;
        for(int i = 0; i<n ; i++)
        {
            if(matrix[i][0] == 1)
                q.push({i,0});
            if(matrix[i][m-1] == 1)
                q.push({i,m-1});
        }
        for(int j = 0; j<m; j++)
        {
            if(matrix[0][j] == 1)
                q.push({0, j});
            if(matrix[n-1][j] == 1)
                q.push({n-1,j});
        }
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            matrix[x][y] = 0;
            for(int k = 0; k<4 ;k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx>=0 and ny>=0 and nx<n  and ny<m and !vis[nx][ny] and matrix[nx][ny] == 1)
                {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        int ans = 0;
        for(int i =0; i<n ;i++)
        {
            for(int j = 0; j<m-1; j++)
            {
                ans +=matrix[i][j];
            }
        }
        return ans;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends