//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int> (n,0));
        queue <pair<int, int>> q;
        for(int i = 0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                    break;
                }
            }
            if(!q.empty())
                break;
        }
        int ax[] = { 1, 0, -1, 0};
        int ay[] = { 0, 1, 0, -1};
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k =0 ; k<4 ; k++)
            {
                int nx = x + ax[k];
                int ny = y + ay[k];
                if(nx>=0  and nx<n and ny>=0 and ny<n and !vis[nx][ny])
                {
                    if(grid[nx][ny] == 2)
                        return true;
                    else if(grid[nx][ny] == 3)
                        q.push({nx,ny});
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends