//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long fun(int i, int j, int n, int cnt, int arr[], vector<vector<long long>> &dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(cnt%2==0)
            return dp[i][j] = max(arr[i] + fun(i+1,j,n,cnt+1,arr,dp), arr[j] + fun(i,j-1,n,cnt+1,arr,dp));
        //else
        return dp[i][j] = min(fun(i+1,j,n,cnt+1,arr,dp), fun(i,j-1,n,cnt+1,arr,dp));
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<long long>> dp(n, vector<long long>(n,-1));
        
        return fun(0,n-1,n,0,arr,dp);
        
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends