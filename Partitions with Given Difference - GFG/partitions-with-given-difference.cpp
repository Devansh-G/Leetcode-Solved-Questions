//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int target, vector<int>& nums) {
        // Code here
        int mod = 1e9+7;
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
                not_take = dp[j]%mod;
                if(j-nums[i]>=0)
                    take = dp[j-nums[i]]%mod;
                dp[j] = (take + not_take)%mod; 
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
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends