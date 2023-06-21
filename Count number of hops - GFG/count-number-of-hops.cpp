//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long count(int i, vector<long long> &dp)
    {
        if(i<0)
            return 0;
        if(i==0)
            return 1;
        int mod = 1e9 +7;
        if(dp[i]!=-1)
            return dp[i]%mod;
        
        long long first = count(i-1,dp) % mod;
        long long second = count(i-2, dp) %mod;
        long long third = count(i-3,dp) %mod;
        return dp[i] = (first + second + third)%mod;
    }
    long long countWays(int n)
    {
        
        // your code here
        vector<long long> dp(n+1,-1);
        dp[0] = 1;
        return count(n, dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends