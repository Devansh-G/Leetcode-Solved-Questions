//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  //      MEMOIZATION
    // int fun(int i, int j, vector<vector<int>>&dp)
    // {
    //     int mod=1e9 + 7;
    //     if(i==0 && j==0)
    //         return dp[i][j]=1;
    //     if(i<0 || j<0)
    //         return 0;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j]%mod;
    //     long long up=fun(i-1,j,dp)%mod;
    //     long long left = fun(i,j-1,dp)%mod;
    //     return dp[i][j] = (up + left)%mod; 
    // }
    long long int numberOfPaths(int m, int n){
        // code here
        //              MEMOIZATION
        // vector<vector<int>> dp(m,vector<int> (n,-1));
        // fun(m-1,n-1,dp);
        // int mod=1e9 + 7;
        // return dp[m-1][n-1]%mod;
        

        //              TABULATION
        // dp[0][0]=1;
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(i==0 && j==0)
        //             continue;
        //         int up = 0, left=0;
        //         if(i>0)
        //             up=dp[i-1][j];
        //         if(j>0)
        //             left=dp[i][j-1];
        //         dp[i][j] = up + left;
        //     }
        // }
        // return dp[m-1][n-1];



        //          SPACE OPTIMATION
        // vector<int> v(n,1), temp;
        // for(int i=1;i<m;i++)
        // {
        //     temp=v;
        //     for(int j=1;j<n;j++)
        //     {   
        //         v[j] = v[j-1] + temp[j];
        //     }
        // }
        // return v[n-1];



        //      EVEN LESS SPACE
        //          SPACE OPTIMATION
        vector<long int> v(n,1);
        int mod=1e9 + 7; 
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++) 
            {
                v[j] += v[j-1];
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
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends