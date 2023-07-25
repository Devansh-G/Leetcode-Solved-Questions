//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        vector<int> dp(n,1), hash(n,0);
        int last_index=0, maxi =0;
        for(int i=1;i<n;i++)
        {
            hash[i] = i;
            for(int j = 0;j<i;j++)
            {
                if(arr[i] % arr[j]==0 and dp[j] + 1 >dp[i])
                {
                    dp[i] = dp[j] + 1;
                    hash[i]=j;
                }
            }
            if(maxi < dp[i])
            {
                maxi = dp[i];
                last_index = i;
            }
        }
        vector<int> ans;
        ans.push_back(arr[last_index]);
        while(last_index != hash[last_index])
        {
            last_index = hash[last_index];
            ans.push_back(arr[last_index]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends