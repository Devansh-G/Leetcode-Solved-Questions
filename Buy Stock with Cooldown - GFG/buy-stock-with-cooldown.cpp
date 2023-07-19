//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        // for Tabulation. see 309. Best Time to Buy and Sell Stock with Cooldown on Leetcode
        
        //0 means can buy, 1 means cant buy, 2 means on cooldown
        
         //Space Optimisation
        
        vector<long long> curr(3,0), next(3,0);
        for(int i=n-1; i>=0; i--)
        {
            // can buy (may or may not buy)
            curr[0] = max(next[1] - prices[i], next[0]);
            //cant buy (may or may not sell)
            curr[1] = max(next[2] + prices[i], next[1]);
            //on cooldown
            curr[2] = next[0];
            
            next=curr;
        }
        return curr[0];
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
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends