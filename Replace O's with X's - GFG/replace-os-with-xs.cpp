//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>> ans(n,vector<char>(m,'X'));
        vector<vector<int>> vis(n, vector<int> (m,0));
        queue<pair<int, int>> q;
        for(int i=0 ;i<n;i++)
        {
            if(!vis[i][0] and mat[i][0] == 'O')
            {
                q.push({i,0});
                vis[i][0] =1;
            }
            if(!vis[i][m-1] and mat[i][m-1] == 'O')
            {
                q.push({i,m-1});
                vis[i][m-1] =1;
            }
        }
        for(int j=0 ;j<m;j++)
        {
            if(!vis[0][j] and mat[0][j] == 'O')
            {
                q.push({0,j});
                vis[0][j] =1;
            }
            if(!vis[n-1][j] and mat[n-1][j] == 'O')
            {
                q.push({n-1,j});
                vis[n-1][j] =1;
            }
        }
        int ax[] = { 1, 0 ,-1, 0};
        int ay[] = { 0, 1, 0, -1};
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            ans[x][y] = 'O';
            for(int k = 0; k<4 ; k++)
            {
                int nx = x + ax[k];
                int ny = y + ay[k];
                if(nx >=0 and nx < n and ny>=0 and ny<m and !vis[nx][ny] and mat[nx][ny] == 'O')
                {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends