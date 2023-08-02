//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>> matrix = grid;
        int count = 0;
        queue<pair<int,int>> q;
        int n = grid.size(), m = grid[0].size();
        int ax[] = {0,0,-1,1};
        int ay[] = {-1,1,0,0};
        for(int i =0 ; i<n;i++)
        {
            for(int j=0 ; j<m ;j++)
            {
                if(matrix[i][j]==2)
                    q.push({i,j});
            }
        }   
        int len = q.size();
        while(!q.empty())
        {
            if(len>0)
                len--;
            else if(len==0)
            {
                len = q.size()-1;
                count++;
            }
            pair<int, int> p = q.front();
            q.pop();
            for(int k =0 ;k<4 ;k++)
            {
                int nx = p.first + ax[k];
                int ny = p.second + ay[k];
                if(nx>=0 and nx < n and ny >= 0 and ny<m and matrix[nx][ny] == 1)
                {
                    matrix[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
        }
        for(int i =0 ;i<n ;i++)
        {
            for(int j = 0; j<m ;j++)
            {
                if(matrix[i][j]==1)
                    return -1;
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
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends