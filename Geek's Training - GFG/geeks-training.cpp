//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  //                    MEMOIZATION
  
    // int fun(vector<vector<int>> &points, vector<vector<int>> &dp, int n, int last)
    // {
    //     if(n<0)
    //         return 0;
    //     int maxi=INT_MIN;
    //     if(dp[n][last]!=-1)
    //         return dp[n][last];
    //     for(int i=0;i<3;i++)
    //     {
    //         if(i!=last)
    //             maxi=max(maxi,points[n][i] + fun(points,dp,n-1,i));
    //     }
    //     return dp[n][last]=maxi;
    // }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        
        //      MEMOIZATION
        
        // vector<vector<int>> dp(n,vector<int> (4,-1));
        // return fun(points, dp , n-1, 3);
        
        //Tabulation
        
        // vector<vector<int>> dp(n,vector<int> (4,-1));
        
        // for(int last=0;last<=3;last++)
        // {
        //     int maxi=0;
        //     for(int i=0;i<3;i++)
        //     {
        //         if(i!=last)
        //             maxi=max(maxi,points[0][i]);
        //     }
        //     dp[0][last]=maxi;
        // }
        
        // for(int day=1;day<n;day++)
        // {
        //     for(int last=0;last<4;last++)
        //     {
        //         int maxi=0;
        //         for(int i=0;i<3;i++)
        //         {
        //             if(i!=last)
        //                 maxi=max(maxi, points[day][i] + dp[day-1][i]);
        //         }
        //         dp[day][last]=maxi;
        //     }
        // }
        // return dp[n-1][3];
        
        //Space Optimisation
        
        vector<int> prev(4,0), curr(4,0);
        for(int day=0; day<n; day++)
        {
            for(int last=0;last<=3;last++)
            {
                int maxi=0;
                for(int i=0;i<3;i++)
                {
                    if(i!=last)
                        maxi=max(maxi , points[day][i] + prev[i]);
                }
                curr[last] = maxi;
            }
            prev=curr;
        }
        
        
        return curr[3];
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