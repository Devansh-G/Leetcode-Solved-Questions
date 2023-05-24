//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fun(vector<vector<int>> &points, vector<vector<int>> &dp, int n, int last)
    {
        if(n<0)
            return 0;
        int maxi=INT_MIN;
        if(dp[n][last]!=-1)
            return dp[n][last];
        for(int i=0;i<3;i++)
        {
            if(i!=last)
                maxi=max(maxi,points[n][i] + fun(points,dp,n-1,i));
        }
        return dp[n][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int> (4,-1));
        return fun(points, dp , n-1, 3);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends