//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int sumOfNaturals(int n) {
        // code here
        
        // long long ans = n;
        // ans*=(n+1);
        // ans/=2;
        // int mod = 1e9 + 7;
        // return ans%mod;
        
        int mod = 1e9 + 7;
        long long ans = n;
        ans*=(n+1);
        ans%=mod;
        ans/=2;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends