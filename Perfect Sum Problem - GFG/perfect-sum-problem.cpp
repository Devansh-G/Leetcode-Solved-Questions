//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod= 1e9 + 7;
	public:
	//          MEMOIZATION
// 	long int fun(int arr[], int ind, int sum, vector<vector<long int>>&dp)
// 	{
// 	    if(ind==0)
// 	    {
// 	        if(sum==0 and arr[0]==0)
// 	            return dp[ind][sum] = 2;
// 	        else if(sum==0)
// 	            return dp[ind][sum] = 1;
// 	        return dp[ind][sum] = (arr[0]==sum);
// 	    }
// 	    if(dp[ind][sum]!=-1)
// 	        return dp[ind][sum];
	    
// 	    long int pick = 0, not_pick=0;
// 	    not_pick = fun(arr,ind-1,sum, dp)%mod;
// 	    if(sum-arr[ind]>=0)
// 	        pick = fun(arr, ind-1, sum-arr[ind], dp)%mod;
// 	    return dp[ind][sum] = (pick + not_pick)%mod;
// 	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        // vector<vector<long int>> dp(n, vector<long int> (sum+1,-1));
        // return fun(arr,n-1,sum, dp);
        
        //      TABULATION
        vector<vector<long int>> dp(n, vector<long int> (sum+1,0));

        if(arr[0]<=sum)
            dp[0][arr[0]]=1;
        dp[0][0]=1;
        if(arr[0]==0)
            dp[0][0]=2;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                long int take=0, not_take=0;
                not_take=dp[i-1][j]%mod;
                if(j-arr[i]>=0)
                    take = dp[i-1][j-arr[i]]%mod;
                dp[i][j] = (take + not_take)%mod;
            }
        }
        return dp[n-1][sum];
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends