//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRow(int N, int M, vector<vector<int>> A) {
        // code here
        int minOne=INT_MAX, index=N;
        int temp=0;
        for(int i=N-1;i>=0;i--)
        {
            temp=0;
            for(int j=M-1; j>=0;j--)
            {
                if(A[i][j])
                    temp++;
            }
            if(minOne>=temp)
            {
                minOne=temp;
                index=i;
            }
        }
        return index+1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends