//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    // longesyt increasing subsequence
    int lis(int arr[], int n)
    {
        vector<int> dp;
        dp.push_back(arr[0]);
        for(int i=1;i<n;i++)
        {
            if(arr[i] > dp.back())
                dp.push_back(arr[i]);
            else
            {
                int ind = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
                dp[ind] = arr[i];
            }
        }
        return dp.size();
    
    }
    
    int removeStudents(int H[], int N) {
        // code here
        return N - lis(H, N);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends