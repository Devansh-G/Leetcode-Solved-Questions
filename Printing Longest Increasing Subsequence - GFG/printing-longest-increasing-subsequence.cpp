//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        // REFER TO NOTES AND Longest Increasing Subsequence on GFG
        vector<int> ans;
        vector<int> hash(n,0) , dp(n,1);
        int maxi = 0, last_index=0;
        
        for(int i=1 ; i<n ; i++)
        {
            hash[i] = i;
            for(int j = 0 ; j<i ;j++)
            {
                if( arr[j] < arr[i] and 1 + dp[j] > dp[i])
                {
                    hash[i] = j;
                    dp[i] = dp[j] + 1;
                }
            }
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                last_index = i;
            }
        }
        ans.push_back(arr[last_index]);
        while(last_index!=hash[last_index])
        {
            last_index = hash[last_index];
            ans.push_back(arr[last_index]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends