//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        //for memoization see notes, for Tabulation  see 44. Wildcard Pattern Matching on Leetcode
        int n=str.length(), m=pattern.length();
        vector<int> curr(m+1,0), prev(m+1,0);
        
        for(int j=0;j<=m;j++)
        {
            bool flag=true;
            for(int k=0;k<j;k++)
            {
                if(pattern[k]!='*')
                    flag=false;
            }
            if(flag)
                curr[j]=1;
        }
        for(int i=1;i<=n;i++)
        {
            prev=curr;
            curr[0]=false;
            for(int j=1;j<=m;j++)
            {
                if(str[i-1]==pattern[j-1] || pattern[j-1]=='?')
                    curr[j]= prev[j-1];
                else if(pattern[j-1]=='*')
                    curr[j] = prev[j] || curr[j-1] || prev[j-1];
                else
                    curr[j]=0;
            }
        }
        return (curr[m]?1:0);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends