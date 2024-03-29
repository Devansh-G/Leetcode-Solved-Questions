//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        int ans = 0;
        //double f[n];
        unordered_map<double, int> mp;
        for(int i=0; i<n ;i++)
        {
            double frac = 1.0 * numerator[i] / denominator[i];
            mp[frac] ++;
        }
        for (int i = 0; i<n ;i++)
        {
            double frac = (1.0 * numerator[i]) / denominator[i];
            double inv = (1.0 * (denominator[i] - numerator[i])) / denominator[i];
            if(frac == 0.5)
            {
                ans += (mp[frac] * (mp[frac] - 1)) / 2;
                mp.erase(frac);
            }
            else
            {
                ans += mp[frac] * mp[inv];
                mp.erase(frac);
                mp.erase(inv);
            }
        }
        return ans;
        
        
        // int res =0;
        // double val[n];
        // unordered_map<double,int> mp;
        // for(int i=0; i<n; i++){
        //     val[i] = 1.0*numerator[i]/denominator[i];
        //     mp[val[i]]++;
            
        // }
       
        // for(int i=0; i<n; i++)
        // {
        //     double a=double(denominator[i]-numerator[i])/double(denominator[i]);
        //     mp[val[i]]--;
        //     res += mp[a];
        // }
        // return res;

        
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends