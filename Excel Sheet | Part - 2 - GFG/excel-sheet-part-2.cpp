//{ Driver Code Starts
//Initial template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    int ExcelColumnNumber(string s)
    {
        // Your code goes here
        int n = s.length();
        int ans = 0;
        for(int i = 0 ; i<n ; i++)
            ans += (s[i] - 'A' +1) * pow(26,n-1-i);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.ExcelColumnNumber(s)<<endl;
    }
}
// } Driver Code Ends