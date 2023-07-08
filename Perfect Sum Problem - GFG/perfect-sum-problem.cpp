//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod= 1e9 + 7;
	public:
	long int fun(int arr[], int ind, int sum, vector<vector<long int>>&dp)
	{
	    if(ind==0)
	    {
	        if(sum==0 and arr[0]==0)
	            return dp[ind][sum] = 2;
	        else if(sum==0)
	            return dp[ind][sum] = 1;
	        return dp[ind][sum] = (arr[0]==sum);
	    }
	    if(dp[ind][sum]!=-1)
	        return dp[ind][sum];
	    
	    long int pick = 0, not_pick=0;
	    not_pick = fun(arr,ind-1,sum, dp)%mod;
	    if(sum-arr[ind]>=0)
	        pick = fun(arr, ind-1, sum-arr[ind], dp)%mod;
	    return dp[ind][sum] = (pick + not_pick)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<long int>> dp(n, vector<long int> (sum+1,-1));
        return fun(arr,n-1,sum, dp);
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