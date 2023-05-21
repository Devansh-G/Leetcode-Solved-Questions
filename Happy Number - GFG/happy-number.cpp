//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isHappy(int n){
        // code here
        if(n==1 || n==7)
            return 1;
        if(n<=9)
            return 0;
        int ans=0;
        while(n>0)
        {
            ans+=((n%10) * (n%10));
            n/=10;
        }
        return isHappy(ans);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends