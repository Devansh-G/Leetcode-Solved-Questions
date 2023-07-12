//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    int left=0, ans=0;
    unordered_map<char, int> m;
    for(int i=0;S[i]!='\0';i++)
    {
        m[S[i]]++;
        while(m[S[i]]>1)
        {
            m[S[left]]--;
            left++;
        }
        ans = max(ans, i-left+1);
    }
    return ans;
}