//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int> dp(W+1,0);
        for(int i=wt[0];i<=W;i++)
            dp[i] = (int)(i/wt[0])*val[0];
        for(int i=1; i<N; i++)
        {
            for(int j=1;j<=W;j++)
            {
                int pick=0, not_pick=0;
                not_pick=dp[j];
                if(j>=wt[i])
                    pick = val[i] + dp[j-wt[i]];
                dp[j] = max(pick, not_pick);
            }
        }
        return dp[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends