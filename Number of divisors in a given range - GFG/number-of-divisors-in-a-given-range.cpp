//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int fun(int num, int n)
    {
        return n/num;
    }
    int hcf(int a, int b)
    {
        if(a==0)
            return b;
        return hcf(b%a,a);
    }
    int lcm(int a, int b)
    {
        return (a*b)/hcf(min(a,b), max(a,b));
    }
    int numOfDiv(int m, int n, int a, int b) {
        // code here
        int ans=0;
        if(a==b)
        {
            ans=fun(a,n) - fun(a,m);
            if(m%a==0)
                ans++;
        }
        else
        {
            ans = fun(a,n) + fun(b,n) - fun(lcm(a,b),n) - fun(a,m) - fun(b,m) + fun(lcm(a,b),m);
            //cout<<ans<<endl;
            if(m % a==0 || m%b==0)
                ans++;
            else if(m % lcm(a,b) == 0)
                ans++;
        }
        //ans = fun(a,n) + fun(b,n) /*- fun(lcm(a,b),n) */- fun(a,m) - fun(b,m)/* + fun(lcm(a,b),m)*/;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m,n,a,b;
        
        cin>>m>>n>>a>>b;

        Solution ob;
        cout << ob.numOfDiv(m,n,a,b) << endl;
    }
    return 0;
}
// } Driver Code Ends