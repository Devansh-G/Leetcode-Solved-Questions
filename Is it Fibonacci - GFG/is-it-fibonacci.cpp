//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        vector<long long> v;
        long long sum=0;
        int i=0;
        for( ;i<K;i++)
        {
            v.push_back(GeekNum[i]);
            sum+=GeekNum[i];
        }
        while(i<N)
        {
            v.push_back(sum);
            sum-=v[i-K];
            sum+=v[i];
            i++;
        }
        return v[N-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends