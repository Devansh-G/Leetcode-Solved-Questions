//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	   // int fun(int n, int m, vector<int> &dp)
	   // {
	   //     if(n<m)
	   //         return 1;
	   //     if(n==m)
	   //         return 2;
	   // }
		int countWays(int n, int m)
	    {
	    // Code here.
	    int mod=1e9 + 7;
	    if(n<m)
	        return 1;
	    if(n==m)
	        return 2;
	    
	    vector<long long> dp(n+1,0);
	    
	    for(int i=1;i<m;i++)
	        dp[i]=1;
	    dp[m]=2;
	    
	    for(int i=m+1;i<=n;i++)
            dp[i]=(dp[i-1]+dp[i-m])%mod;
            
	    return dp[n];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.countWays(n, m);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends