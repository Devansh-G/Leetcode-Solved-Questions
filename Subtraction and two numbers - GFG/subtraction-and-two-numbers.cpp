//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
    int fun(int a, int b)
    {
        if(a==0)
            return 0;
        return b/a + fun(b%a, a);
    }
    int repeatedSubtraction(int A,int B){
        //code here
        if(A==B)
            return 1;
        return fun(min(A,B), max(A,B));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.repeatedSubtraction(A,B)<<"\n";
    }
}
// } Driver Code Ends