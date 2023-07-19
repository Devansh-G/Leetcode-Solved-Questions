//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
    vector<vector<int>> curr(2, vector<int> (K+1,0)), next(2, vector<int> (K+1,0));
    //for reference, see Buy and Sell a Share at most twice on GFG
    for(int i=N-1;i>=0;i--)
    {
        next=curr;
        for(int buy=0;buy<2;buy++)
        {
            for(int t=0;t<K;t++)
            {
                if(buy)
                    curr[buy][t] = max(next[0][t] - A[i], next[1][t]);
                else
                    curr[buy][t] = max(next[1][t+1] + A[i], next[0][t]);
            }
        }
    }
    return curr[1][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends