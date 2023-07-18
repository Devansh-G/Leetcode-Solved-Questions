//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {

        //For memoization see notes, for tabulation see 72. edit distance on Leetcode
        
        int n=s.length(), m= t.length();
        vector<int> prev(m+1,0), curr(m+1,0);
        for(int j=0;j<=m;j++)
            curr[j]=j;
        for(int i=1;i<=n;i++)
        {
            prev=curr;
            for(int j=1;j<=m;j++)
            {
                curr[0]=i;
                if(s[i-1]==t[j-1])
                    curr[j] = prev[j-1];
                else
                {
                    curr[j] = 1+min(prev[j-1] , min(prev[j],curr[j-1]));
                }
            }
        }
        return curr[m];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends