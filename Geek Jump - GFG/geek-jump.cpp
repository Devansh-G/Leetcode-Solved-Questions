//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // int fun(int n, vector<int> &height, vector<int> &dp)
    // {
    //     if(n==0)
    //         return 0;
    //     if(dp[n]!=-1)
    //         return dp[n];
    //     int left= fun(n-1,height, dp) + abs(height[n] - height[n-1]);
    //     int right= INT_MAX;
    //     if(n>1)
    //         right= fun(n-2, height, dp) + abs(height[n] - height[n-2]);
    //     return dp[n] = min(left, right);
    // }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        // vector<int> dp(n+1,-1);
        // return fun(n-1,height,dp);
        
        if(n<2)
            return 0;
        int prev2 = 0, prev= abs(height[1] - height[0]);
        //int ans=0;
        int ans= min(prev2 + abs(height[2] - height[0]), prev + abs(height[2] - height[1]));
        for(int i=2;i<n;i++)
        {
            ans= min(prev2 + abs(height[i] - height[i-2]), prev + abs(height[i] - height[i-1]));
            prev2 = prev;
            prev = ans;
        }
        return prev;
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
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends