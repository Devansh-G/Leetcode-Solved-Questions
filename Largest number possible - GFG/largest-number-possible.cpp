//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        if(N==1 && S==0)
            return "0";
        else if(S==0)
            return "-1";
        int count=0;
        string num;
        while(S>=9 && count<N)
        {
            num+='9';
            S-=9;
            count++;
        }
        if(S>0 && count<N)
        {
            count++;
            num += S +'0';
            S=0;
        }
        while(count<N)
        {
            count++;
            num+='0';
        }
        if(S!=0)
            return "-1";
        return num;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends