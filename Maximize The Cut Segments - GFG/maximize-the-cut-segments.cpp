//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1,0);
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        for(int i=1; i<=n; i++)
        {
            a = INT_MIN;
            b = INT_MIN;
            c = INT_MIN;
            if(i-x>=0)
                a=dp[i-x];
            if(i-y>=0)
                b=dp[i-y];
            if(i-z>=0)
                c=dp[i-z];
            dp[i] = max(max(a,b),c) + 1;
        }
        if(dp[n]<0)
            return 0;
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends