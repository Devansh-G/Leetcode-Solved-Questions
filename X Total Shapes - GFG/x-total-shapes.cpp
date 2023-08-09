//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
     void bfs(int &i, int &j, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i,j});
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k = 0; k<4 ; k++)
            {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx>=0 and nx < n and ny >= 0 and ny < m and !vis[nx][ny] and grid[nx][ny] == 'X')
                {
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        return ;
    }
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis (n, vector<int> (m,0));
        for(int i = 0; i<n ;i++)
        {
            for(int j= 0 ; j<m ;j++)
            {
                if(!vis[i][j] and grid[i][j] == 'X')
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
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends