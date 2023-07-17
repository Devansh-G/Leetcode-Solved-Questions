//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    
    //MEMOIZATION
    // int fun(int i, int j, string &a, string &b, vector<vector<int>> &dp)
    // {
    //     if(i<0 and j<0)
    //         return 0;
    //     if(i<0)
    //         return j+1;
    //     if(j<0)
    //         return i+1;
            
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
            
    //     if(a[i]==b[j])
    //         return dp[i][j] = 1 + fun(i-1,j-1,a,b,dp);
    //     return dp[i][j] = 1 + min(fun(i-1,j,a,b,dp), fun(i,j-1,a,b,dp)); 
    // }
    
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        
        //MEMOIZATION
        // vector<vector<int>> dp(m, vector<int> (n,-1));
        // return fun(m-1,n-1, X,Y, dp);
    
        //TABULATION
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i=1; i<=m;i++)
            dp[i][0] = i;
        for(int j=1; j<=n;j++)
            dp[0][j] = j;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(X[i-1] == Y[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j]  = 1 + min(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[m][n];
        //DO SPACE OPTIMISATION ON YOUR OWN
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends