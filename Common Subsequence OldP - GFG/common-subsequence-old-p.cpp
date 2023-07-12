//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    int commonSubseq(string S1, string S2){
        // code here
        unordered_map<char,int> m;
	    for(int i=0;S1[i]!='\0';i++)
	        m[S1[i]]++;
	    for(int i=0;S2[i]!='\0';i++)
	    {
	        if(m[S2[i]]!=0)
	            return 1;
	    }
	    return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1, S2;
        cin >> S1 >> S2;
        Solution ob;
        cout << ob.commonSubseq(S1, S2) << endl;
    }
    return 0;
}

// } Driver Code Ends