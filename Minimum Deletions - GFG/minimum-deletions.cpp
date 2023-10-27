//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  int lcs(string a, string b, int n)
    {
        vector<int> dp(n+1,0), temp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[j]= temp[j-1] + 1;
                else
                    dp[j] = max(temp[j], dp[j-1]);
            }
            temp=dp;
        }
        return dp[n];
    }
    int minimumNumberOfDeletions(string S) { 
        // code here
        string B=S;
        reverse(B.begin(),B.end());
        return S.length() - lcs(S,B,S.length());
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends