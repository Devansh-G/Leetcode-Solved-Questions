//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int subsequenceCount(string S, string T)
    {
      //Your code here
      int n=S.length(), m=T.length();
      vector<int> curr(m+1,0);
      curr[0]=1;
      int mod = 1e9 + 7;
      for(int i = 1;i<=n;i++)
      {
          for(int j=m;j>0;j--)
          {
                if(S[i-1] == T[j-1])
                    curr[j] = (curr[j] + curr[j-1])%mod;
          }
      }
      return curr[m];
      //For memoization see notes, and tabulation from 115. Distinct Subsequences from leetcode
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends