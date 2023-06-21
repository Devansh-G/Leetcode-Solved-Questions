//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int fun(int i, vector<int> &dp)
	    {
	        if (i<0)
	            return 0;
	        if(i<2)
	            return 1;
	        if(dp[i]!=-1)
	            return dp[i];
	        int mod= 1e9 + 7;
	        return dp[i] = (fun(i-1,dp) + fun(i-2,dp))%mod;
	    }
		int nthPoint(int n){
		    // Code here
		    vector<int> dp(n+1,-1);
		    return fun(n,dp);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends