//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    //using dp
    long long int fun(int n, vector<long long int> &dp)
    {
        if(n==0 || n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int left = fun(n-1, dp);
        int right = fun(n-2, dp);
        long int mod=1e9;
        return dp[n] = (left + right) % (mod + 7 );
    }
    int countWays(int n)
    {
        // your code here
        vector <long long int> dp(n + 1,-1);
        return fun(n,dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends