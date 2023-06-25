//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void fun(vector<vector<int>> &b, vector <int> &v, int i, int j, int &n, int&m, vector<vector<int>> &grid)
    {
        if(i==n-1 && j==m-1)
        {
            b.push_back(v);
            return;
        }
        if(i==n || j==m)
            return;
        
        
        //down
        if(i<(n-1))
        {
            v.push_back(grid[i+1][j]);
            fun(b,v,i+1,j,n,m,grid);
            v.pop_back();
        }
        

        //right
        if(j<(m-1))
        {
            v.push_back(grid[i][j+1]);
            fun(b,v,i,j+1,n,m,grid);
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<vector<int>> b;
        vector<int> v;
        v.push_back(grid[0][0]);
        fun(b,v,0,0,n,m,grid);
        return b;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

// } Driver Code Ends