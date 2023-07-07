//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int fun(int arr[], int &N, int i, int target)
    // {
        
    // }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=arr[i];
        if(sum%2)
            return 0;
        sum/=2;
        vector<vector<int>> dp(n, vector<int> (sum+1,-1));
        for(int i=0 ;i<n ;i++)
        {
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int target=1; target<=sum; target++)
            {
                if(i==0)
                    dp[i][target] = (arr[0]==target);
                else
                {
                    bool not_take = dp[i-1][target];
                    bool take = false;
                    if(target-arr[i]>=0)
                        take = dp[i-1][target-arr[i]];
                    dp[i][target] = take | not_take;
                }
            }
        }
        
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends