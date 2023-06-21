//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  //              MEMOIZATION
    // long long fun(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&grid)
    // {
    //      int mod = 1e9 + 7;
    //     if(i<0 || j<0)
    //         return 0;
    //     if(grid[i][j]==0)
    //         return dp[i][j] = 0;
    //     if(i==0 && j==0)
    //         return dp[i][j]=1;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j]%mod;
    //     long long up=fun(i-1,j,dp,grid)%mod;
    //     long long left = fun(i,j-1,dp,grid)%mod;
    //     return dp[i][j] = (up + left)%mod; 
    // }
    int uniquePaths(int m, int n, vector<vector<int>> &grid) {
        // code here
        
        //OUR ARRAY IS M*N INSTEAD OF N*M
        
        int mod=1e9 + 7;
        
        if(grid[0][0] == 0)
            return 0;
        //              MEMOIZATION
        // vector<vector<int>> dp(m,vector<int> (n,-1));
        // fun(m-1,n-1,dp,grid);
        // return dp[m-1][n-1]%mod;


        //              TABULATION
        // vector<vector<long>> dp(m,vector<int> (n,-1));
        // dp[0][0]=1;
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(i==0 && j==0)
        //             continue;
        //         if(grid[i][j]==0)
        //         {
        //             dp[i][j]=0;
        //             continue;
        //         }
        //         int up = 0, left=0;
        //         if(i>0)
        //             up=dp[i-1][j]%mod;
        //         if(j>0)
        //             left=dp[i][j-1]%mod;
        //         dp[i][j] = (up + left)%mod;
        //     }
        // }
        // return dp[m-1][n-1]%mod;


        //          SPACE OPTIMATION
        vector<long> v(n,0), temp;
        v[0] = 1;
        for(int i=0;i<m;i++)
        {
            //temp=v;
            
            for(int j=0;j<n;j++)
            {   
                if(grid[i][j]==0)
                    v[j]=0;
                //v[j] = temp[j];
                else if(j>0)
                    v[j]+=v[j-1];
                v[j]%=mod;
            }
        }
        return v[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends