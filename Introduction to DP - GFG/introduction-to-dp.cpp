//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    long long int fun(int n, vector<int> &dp)
    {
        long int mod = 1e9 + 7;
        if(n<0)
            return 0;
        else if(n<=1)
            return dp[n] = n;
        else if(dp[n]!=-1)
            return dp[n] % mod;
            
        return dp[n] = (fun(n-1, dp)%mod) + (fun(n-2, dp)%mod);
    }
    long long int topDown(int n) {
        // code here
        vector<int> dp (n+1,-1);
        long int mod = 1e9 + 7;
        return fun(n, dp) % mod;
    }
    long long int bottomUp(int n) {
        // code here
        long long int prev2=0, prev=1, curr=0;
        long int mod = 1e9 + 7;
        for(int i=1;i<n;i++)
        {
            curr=prev+prev2;
            curr%=mod;
            prev2=prev;
            prev=curr;
        }
        //cout<<prev<<endl;
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends