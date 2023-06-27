//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    //           MEMIOZATION
    // int fun(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j, int &n)
    // {
    //     if(j<0 || j>=n)
    //         return -1e9;
    //     if(i==0)
    //         return dp[i][j] =  grid[i][j];
        
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
        
    //     int s= fun(grid, dp, i-1,j,n);
    //     int ld= fun(grid, dp, i-1,j-1,n);
    //     int rd= fun(grid, dp, i-1,j+1,n);
        
    //     return dp[i][j] =  grid[i][j] + max(s, max(ld,rd));
    // }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        //      MEMOIZATION
        // vector<vector<int>> dp(N, vector<int> (N,-1));
        // int maxi=fun(Matrix, dp, N-1, 0,N);
        // for(int j=1 ; j<N ; j++)
        //     maxi = max(maxi, fun(Matrix, dp, N-1, j,N));
        // return maxi;
        
        
        //      TABULATION
        // vector<vector<int>> dp(N, vector<int> (N,-1));
        // for(int i=0;i<N;i++)
        // {
        //     for(int j=0;j<N;j++)
        //     {
        //         if(i==0)
        //         {
        //             dp[i][j] = Matrix[i][j];
        //             continue;
        //         }
                
        //         int rd =-1e9, ld=-1e9;
        //         int s = Matrix[i][j] + dp[i-1][j];
        //         if(j>0) 
        //             ld= Matrix[i][j] + dp[i-1][j-1];
                
        //         if(j<N-1) 
        //             rd = Matrix[i][j] + dp[i-1][j+1];
                    
        //         dp[i][j] = max(s, max(rd,ld));
        //     }
        // }
        
        // int maxi=dp[N-1][0];
        // for(int j=1;j<N;j++)
        //     maxi= max(maxi, dp[N-1][j]);
        // return maxi;
        
        //      SPACE OPTIMISATION
        vector<int> curr(N,-1), prev(N,-1);
        
        for(int i=0;i<N;i++)
        {
            prev=curr;
            for(int j=0;j<N;j++)
            {
                if(i==0)
                {
                    curr[j]= Matrix[i][j];
                    continue;
                }
                int s = Matrix[i][j] + prev[j];
                int rd=-1e9, ld=-1e9;
                if(j>0)
                    ld = Matrix[i][j] + prev[j-1];
                if(j<N-1)
                    rd = Matrix[i][j] + prev[j+1];
                curr[j] = max(s, max(rd,ld));
            }
        }
        
        int maxi = curr[0];
        for(int j=1;j<N;j++)
            maxi= max(maxi, curr[j]);
    
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends