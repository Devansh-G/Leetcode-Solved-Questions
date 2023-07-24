//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fun(vector<int> &arr, int &k, int &day)
    {
        int count=0, ans=0;
        for(auto &ele : arr)
        {
            if(ele <=day)
                count++;
            else
                count=0;
            if(count == k)
            {
                ans++;
                count=0;
            }
        }
        return ans;
    }
    int solve(int M, int K, vector<int> &bloomDay){
      // Code here
      int n=bloomDay.size();
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        if((long)M*K > n)
            return -1;
        int mid=(low+high)/2;
        while(low<=high)
        {
            mid=(low+high)/2;
            int bouquets = fun(bloomDay, K, mid);
            if(bouquets >= M)
                high = mid-1;
            else
                low = mid + 1;
        }
        return low;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends