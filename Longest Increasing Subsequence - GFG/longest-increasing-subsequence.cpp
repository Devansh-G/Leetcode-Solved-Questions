//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    int lowerBound(vector<int> &dp, int &target)
    {
        int low = 0, high = dp.size()-1;
        while(low<=high)
        {
            int mid= (low + high)/2;
            if(dp[mid] == target)
                return mid;
            else if(dp[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
    //MEMOIZATION
    // int lis(int i, int n, int prev, int arr[], vector<vector<int>> &dp)
    // {
    //     if(i==n)
    //         return 0;
    //     if(dp[i][prev + 1] !=-1)
    //         return dp[i][prev + 1];
            
    //     //TAKE CASE
    //     if(prev == -1 || arr[prev] < arr[i])
    //         return dp[i][prev + 1] = max(1 + lis(i+1, n , i, arr, dp), lis(i+1,n, prev, arr, dp));
            
    //     //NOT TAKE CASE 
    //     return dp[i][prev + 1] =  lis(i+1,n, prev, arr, dp);
    
    // }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // MEMOIZATION
    //   vector<vector<int>> dp(n, vector<int> (n + 1,-1));
    //     return lis(0,n, -1, a, dp);
    
        //TABULATION
        // vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int prev = i-1; prev>=-1 ; prev--)
        //     {
        //         int len = dp[i+1][prev + 1];
        //         if(prev == -1 || a[i] > a[prev])
        //             len = max(len , 1 + dp[i+1][i + 1]);
        //         dp[i][prev + 1] = len; 
        //     }
        // }
        // return dp[0][-1 + 1];
        
        // do two 1D space optimisation from above code
        
        //1D space optimisation (this does not decrease the time complexity in this case, but is vey helpful in case of printing LIS)
        // this hash is used for printing the LIS
        // vector<int> hash(n,0) , dp(n,1);
        // int maxi = 0, last_index=0;
        
        // for(int i=1 ; i<n ; i++)
        // {
        //     hash[i] = i;
        //     for(int j = 0 ; j<i ;j++)
        //     {
        //         if( a[j] < a[i] and 1 + dp[j] > dp[i])
        //         {
        //             hash[i] = j;
        //             dp[i] = dp[j] + 1;
        //         }
        //     }
        //     if(dp[i] > maxi)
        //     {
        //         maxi = dp[i];
        //         last_index = i;
        //     }
        // }
        // return maxi;
        
        
        //Using Binary Search
        vector<int> lis;        //This is not our actual LIS
        lis.push_back(a[0]);
        for(int i=1 ; i<n; i++)
        {
            if(a[i] > lis.back())
                lis.push_back(a[i]);
            else
            {
                int ind = lowerBound(lis, a[i]);
                lis[ind] = a[i];
            }
        }
        return lis.size();
    }
    
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends