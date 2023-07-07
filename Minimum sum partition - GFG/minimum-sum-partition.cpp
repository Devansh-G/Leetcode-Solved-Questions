//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    if(n==1)
	        return arr[0];
	    int sum=0;
	    for(int i=0;i<n;i++)
	        sum+=arr[i];
	    vector<vector<int>> dp(n, vector<int>(sum+1,0));
	   // for(int target =1; target<=sum ; target++)
	   //     dp[0][target] = (arr[0]==target);
	   
	   //           OR
	   dp[0][arr[0]] = 1; 
	    
	    for(int i=0;i<n;i++)
	        dp[i][0] = 1;
	    for(int i=1 ; i<n ; i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            bool not_take=dp[i-1][j];
	            bool take = false;
	            if(j-arr[i]>=0)
	                take = dp[i-1][j-arr[i]];
	            dp[i][j] = (take||not_take);
	        }
	    }
	    
	    int ans=1e9;
	    for(int i=1;i<=sum/2;i++)
	    {
	        if(dp[n-1][i]==1)
	           ans=min(ans, abs(sum - 2*i));
	    }
	    return ans;
	    //For 1D optimisation, See leetcode
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends