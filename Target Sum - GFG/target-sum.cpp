//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&nums ,int target) {
        //Your code here
        int sum=0, mini=INT_MAX,abs_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            //mini=min(mini,nums[i]);
            abs_sum+=abs(nums[i]);
        }
        if((target+sum)%2==1 || abs(target)>abs_sum)
            return 0;
        int new_target=(sum+target)/2;
        vector<int> dp(new_target+1,0);

    /*    for memoization and tabulation see perfect sum problem on GFG, for understanding of
         above code, see notes. or else
         divide array into two subsets S1 and S2
         sum(S1) + sum(S2) = total sum
         sum(S1) - sum(S2) = target
         sum(S1) = (total sum + target)/2
    */
        if(nums[0]<=new_target)
            dp[nums[0]]=1;
        dp[0]=1;
        if(nums[0]==0)
            dp[0]=2;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=new_target;j>=0;j--)
            {
                int take=0, not_take=0;
                not_take = dp[j];
                if(j-nums[i]>=0)
                    take = dp[j-nums[i]];
                dp[j] = take + not_take; 
            }
            // for(int j=0;j<=new_target;j++)
            //     cout<<dp[j]<<" ";
            // cout<<endl;
        }
        return dp[new_target];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends