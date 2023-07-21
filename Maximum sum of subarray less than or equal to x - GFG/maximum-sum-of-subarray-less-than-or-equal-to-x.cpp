//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	int findMaxSubarraySum(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    long long preSum=0;
	    int left=0;
	    long long ans=0;
	    for(int i=0;i<n;i++)
	    {
	        preSum+=arr[i];
	        while(preSum>sum)
	        {
	            preSum-=arr[left];
	            left++;
	        }
	        ans=max(ans, preSum);
	    }
	    return ans;
	}  
};
	  



//{ Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	 int n;
        cin>>n;
        
        long long a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        long long sum;
        cin >> sum;
        

        Solution ob;
		cout << ob.findMaxSubarraySum(a, n, sum);
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends