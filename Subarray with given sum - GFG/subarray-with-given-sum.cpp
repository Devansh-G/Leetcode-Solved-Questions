//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int> ans(2, -1);
        if(s==0)
            return {-1};
        int i = n-1;
        long long curr=0;
        int right = n-1;
        while(i>=0)
        {
            curr += arr[i];
            while(curr > s and i<=right)
            {
                curr-=arr[right];
                right--;
            }
            if(curr == s)
            {
                ans[0] = i+1;
                ans[1] = right+1;
            }
            i--;
        }
        if(ans[0]==-1)
            return {-1};
        return ans;
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends