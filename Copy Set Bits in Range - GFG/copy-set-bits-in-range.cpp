//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    // int bits(int a){
    //     int ans=0;
    //     while(a>0)
    //     {
    //         ans++;
    //         a=a>>1;
    //     }
    //     return ans;
    // }
    int setSetBit(int x, int y, int l, int r){
        // code here
        // l=bits(l);
        // r=bits(r);
        l--;
        r--;
        int mask=0;
        for(int i=0; i<=(r-l); i++)
        {
            mask=mask<<1;
            mask+=1;
            //cout<<mask<<endl;
        }
        for(int i=0;i<l;i++)
            mask=mask<<1;
        //cout<<mask<<endl;
        y=y&mask;
        //cout<<y<<endl;
        return x|y;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends