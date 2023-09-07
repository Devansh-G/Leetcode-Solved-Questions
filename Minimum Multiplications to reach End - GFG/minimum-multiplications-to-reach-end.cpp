//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start == end)    return 0;
        int mod = 1e5;
        queue<pair<int,int>> q;
        vector<bool> vis(1e5 + 1,false);
        q.push({start,0});
        vis[start] = 1;
        while(!q.empty())
        {
            int temp = q.front().first;
            int level = q.front().second;
            q.pop();
            for(auto it : arr)
            {
                int prod = (1ll * temp * it) % mod;
                if(prod == end)
                    return level + 1;
                
                if(!vis[prod])
                {
                    vis[prod] = true;
                    q.push({prod, level + 1});
                }
                else
                    continue;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends