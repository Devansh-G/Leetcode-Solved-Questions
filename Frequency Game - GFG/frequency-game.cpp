//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        vector<int> v(1000001,0);
        int maxi=INT_MIN, minf=INT_MAX;
        for(int i=0;i<n;i++)
        {
            v[arr[i]]++;
            maxi=max(maxi,arr[i]);
        }
        for(int i=0;i<=maxi;i++)
        {
            if(v[i])
                minf=min(minf,v[i]);
        }
        for(int i=maxi;i>=0;i--)
        {
            if(v[i]==minf)
                return i;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends