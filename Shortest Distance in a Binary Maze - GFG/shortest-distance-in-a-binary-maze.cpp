//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        queue<pair<pair<int, int>, int>> q;
        q.push({source,0});
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m,-1));
        dist[source.first][source.second] = 0;
        int ax[] = {1, 0, -1, 0};
        int ay[] = {0, 1, 0, -1};
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int distance = q.front().second;
            if(x == destination.first and y == destination.second)
                return distance;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nx = x + ax[k];
                int ny = y + ay[k];
                if(nx>=0 and nx <n and ny>=0 and ny<m and grid[nx][ny] == 1 and dist[nx][ny] == -1)
                {
                    q.push({{nx,ny}, distance + 1});
                    dist[nx][ny] = distance +1;
                }
            }
        }
        return dist[destination.first][destination.second];
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends