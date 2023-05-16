//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    void fun(vector<vector<int>> &b, vector<int> &v, vector<int> &nums, int index)
    {
        b.push_back(v);
        if(index==nums.size()){
            
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            if(i!=index && nums[i]==nums[i-1])
                continue;
            
            v.push_back(nums[i]);
            fun(b,v,nums, i+1);
            v.pop_back();
            
            //fun(b,v,nums,i+1);
      }
  }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        vector<vector<int>> b;
        vector<int> v;
        sort(nums.begin(),nums.end());
        fun(b,v,nums,0);
        return b;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends