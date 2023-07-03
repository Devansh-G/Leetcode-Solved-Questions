//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(int ind,int sum,vector<int> &arr,vector<vector<int>> &dp)
    {
        if(sum==0)
        return true;

        if(ind<0)
        return false;
        
        if(ind==0)
            return arr[0]==sum;
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        
        
        bool notpick=0,pick=0;
        
        notpick=solve(ind-1,sum,arr,dp);
        
        if(arr[ind]<=sum)
            pick=solve(ind-1,sum-arr[ind],arr,dp);
        
        return dp[ind][sum]= pick+notpick;
        
    }
    bool isSubsetSum(vector<int>arr, int sum)
    {
        // code here 
        int n=arr.size();
        
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        
        return solve(n-1,sum,arr,dp);
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