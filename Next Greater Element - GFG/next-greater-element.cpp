//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        stack<int> st;
        vector<long long> v(n,0);
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
                v[i]=-1;
            else if(arr[st.top()]>arr[i])
                v[i] = arr[st.top()];
            else
            {
                while(!st.empty() && arr[st.top()]<=arr[i])
                    st.pop();
                if(st.empty())
                    v[i]=-1;
                else
                    v[i] = arr[st.top()];
            }
            st.push(i);
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends