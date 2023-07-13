//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int lcs(string &a, string &b)
    {
        int n= a.length(),m=b.length();
        vector<int> curr(m+1,0),prev(m+1,0);
        for(int i=1;i<=n;i++)
        {
            prev=curr;
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                    curr[j]= prev[j-1]+1;
                else
                    curr[j]=max(prev[j],curr[j-1]);
                //cout<<curr[j]<<" ";
            }
            //cout<<endl;
        }
        return curr[m];
    }
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int len=lcs(str1,str2);
        //cout<<len<<endl;
        return str1.length() -len + str2.length() -len;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends