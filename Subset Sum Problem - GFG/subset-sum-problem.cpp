//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    //      MEMOIZATION
    // bool solve(int ind,int sum,vector<int> &arr,vector<vector<int>> &dp)
    // {
    //     if(sum==0)
    //     return true;

    //     if(ind<0)
    //     return false;
        
    //     if(ind==0)
    //         return arr[0]==sum;
    //     if(dp[ind][sum]!=-1)
    //         return dp[ind][sum];
        
        
    //     bool notpick=0,pick=0;
        
    //     notpick=solve(ind-1,sum,arr,dp);
        
    //     if(arr[ind]<=sum)
    //         pick=solve(ind-1,sum-arr[ind],arr,dp);
        
    //     return dp[ind][sum]= pick+notpick;
        
    // }
    bool isSubsetSum(vector<int>arr, int sum)
    {
        //      MEMOIZATION
        // int n=arr.size();
        // vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        // return solve(n-1,sum,arr,dp);
        
        //      TABULATION
        // int n=arr.size();
        // vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
        // for(int i=0;i<n;i++)
        //     dp[i][0]=true;
        // dp[0][arr[0]]=true;
        
        // for(int i=1;i<n;i++)
        // {
        //     for(int target=1; target<=sum; target++)
        //     {
        //         bool take = false, not_take= false;
        //         not_take = dp[i-1][target];
        //         if(target-arr[i]>=0)
        //             take = dp[i-1][target-arr[i]];
        //         dp[i][target] = take || not_take;
        //     }
        // }
        // return dp[n-1][sum];
        
        //Space optimisation
        int n=arr.size();
        vector<bool> prev(sum+1,0), curr(sum+1,0);
        curr[0]=true;
        if(sum>=arr[0])
            curr[arr[0]]=true;
        
        for(int i=1;i<n;i++)
        {
            prev=curr;
            curr[0]=true;
            for(int target=1; target<=sum; target++)
            {
                bool take = false, not_take= false;
                not_take = prev[target];
                if(target-arr[i]>=0)
                    take = prev[target-arr[i]];
                curr[target] = take || not_take;
            }
        }
        return curr[sum];
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends