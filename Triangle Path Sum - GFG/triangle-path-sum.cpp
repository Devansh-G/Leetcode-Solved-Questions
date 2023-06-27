//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  //        MEMOIZATION
  int fun(vector<vector<int>> &triangle,vector<vector<int>> &dp, int i, int j)
  {
        if(i== triangle.size() - 1)
            return triangle[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int d = triangle[i][j] + fun(triangle, dp, i+1,j);
        int dg = triangle[i][j] + fun(triangle, dp, i+1,j+1); 
        
        return dp[i][j] = min(d,dg);
  }
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        
        //MEMOIZATION
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return fun(triangle, dp, 0,0);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends