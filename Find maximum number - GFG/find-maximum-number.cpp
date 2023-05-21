//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string findMax(string N) {
        // code here
        vector<int> a(10,0);
        string ans="";
        for(int i=0;i<N.length();i++)
        {
            a[N[i]-'0']++;
        }
        for(int i=9;i>=0;i--)
        {
            while(a[i]--)
                ans+= i + '0';
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string N;
        
        cin>>N;

        Solution ob;
        cout << ob.findMax(N) << endl;
    }
    return 0;
}
// } Driver Code Ends