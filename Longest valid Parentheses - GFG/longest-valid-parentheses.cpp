//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    int maxLength(string S){
        // code here
        stack<int>st;
        st.push(-1);
        int ans=0;
        for(int i=0;S[i]!='\0';i++)
        {
            if(st.size()==1 || S[i]=='(')
                st.push(i);
            else
            {
                if(S[st.top()]=='(')
                {
                    st.pop();
                    ans=max(ans, i-st.top());
                }
                else
                    st.push(i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends