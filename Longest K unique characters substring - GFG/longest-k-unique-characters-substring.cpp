//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int left=0, n=s.length(), len=-1;
        unordered_map<char, int> freq;
        for(int i=0;i<n;i++)
        {
            freq[s[i]]++;
            while(freq.size()>k)
            {
                freq[s[left]]--;
                if(freq[s[left]]==0)   
                    freq.erase(s[left]);
                left++;
            }
            if(freq.size()==k)
                len=max(len, i-left+1);
        }
        return len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends