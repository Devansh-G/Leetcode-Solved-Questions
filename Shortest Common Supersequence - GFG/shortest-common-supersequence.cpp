//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    
    //Function to calculate longet common subsequence matrix
    // void LCS(string &a, string &b, vector<vector<int>> &lcs)
    // {
    //     for(int i=1; i<=a.length(); i++)
    //     {
    //         for(int j=1; j<=b.length() ;j++)
    //         {
    //             if(a[i-1]==b[j-1])
    //                 lcs[i][j] = lcs[i-1][j-1] + 1;
    //             else
    //                 lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
    //         }
    //     }
    //     return ;
    // }
    
    //MEMOIZATION
    int fun(int i, int j, string &a, string &b, vector<vector<int>> &dp)
    {
        if(i<0 and j<0)
            return 0;
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
            
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        if(a[i]==b[j])
            return dp[i][j] = 1 + fun(i-1,j-1,a,b,dp);
        return dp[i][j] = 1 + min(fun(i-1,j,a,b,dp), fun(i,j-1,a,b,dp)); 
    }
    
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        // vector<vector<int>> lcs(m+1, vector<int> (n+1,0));
        // LCS(X,Y,lcs);
        
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return fun(m-1,n-1, X,Y, dp);
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