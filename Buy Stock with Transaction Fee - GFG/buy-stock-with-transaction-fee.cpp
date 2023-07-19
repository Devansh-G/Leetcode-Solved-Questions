//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        
        //For reference, see 122. Best Time to Buy and Sell Stock II on leetcode
        
        //buy=0 means we cant buy, buy=1 means we can buy
        //Tabulation
        vector<vector<long long>> dp(n+1, vector<long long> (2,0));
        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<2; buy++)
            {
                if(buy)
                    dp[i][buy] = max(dp[i+1][0] - prices[i], dp[i+1][1]);
                else
                    dp[i][buy] = max(dp[i+1][1] + prices[i] - fee, dp[i+1][0]);
            }
        }
        return dp[0][1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends