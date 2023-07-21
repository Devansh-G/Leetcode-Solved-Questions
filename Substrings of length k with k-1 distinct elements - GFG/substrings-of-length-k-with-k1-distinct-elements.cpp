//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string S, int K) {
        // code here
        unordered_map<char, int> freq;
        int left=0, n=S.length(), count=0;
        for(int i=0;i<n;i++)
        {
            freq[S[i]]++;
            while(freq.size()>=K || i-left+1>K)
            {
                freq[S[left]]--;
                if(freq[S[left]]==0)
                    freq.erase(S[left]);
                left++;
            }
            if(freq.size()==K-1 && i-left+1==K)
                count++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends