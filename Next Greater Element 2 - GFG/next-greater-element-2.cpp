//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int n, vector<int>& arr) {
        // code here
        stack<int> st;
        vector<int> v(n,0);
        for(int i=2*n - 1; i>=0;i--)
        {
            if(i>=n)
            {
                if(st.empty());
                else if(arr[st.top()]>arr[i%n]);
                else
                {
                    while(!st.empty() && arr[st.top()] <= arr[i%n])
                        st.pop();
                }
                st.push(i%n);
            }
            else
            {
                if(st.empty())
                    v[i]=-1;
                else if(arr[st.top()]>arr[i])
                    v[i] = arr[st.top()];
                else
                {
                    while(!st.empty() and arr[st.top()] <= arr[i])
                        st.pop();
                    if(st.empty())
                    v[i]=-1;
                    else if(arr[st.top()]>arr[i])
                        v[i] = arr[st.top()];
                }
                st.push(i);
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends