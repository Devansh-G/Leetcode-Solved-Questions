//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int len=INT_MAX, left=0;
        unordered_map<char, int> mp;
        int n=S.length();
        for(int i=0;i<n;i++)
        {
            mp[S[i]]++;
            while(mp.size()==3)
            {
                len=min(len, i-left+1);
                mp[S[left]]--;
                if(mp[S[left]]==0)
                    mp.erase(S[left]);
                left++;
            }
        }
        if(len==INT_MAX)
            return -1;
        return len;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends