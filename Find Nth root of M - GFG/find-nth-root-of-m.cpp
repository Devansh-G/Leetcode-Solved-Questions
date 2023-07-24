//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int power(int m, int n, int x)
	{
	    if(m>x)
	        return 0;
	   long int ans=m;
	   for(int i=1;i<n;i++)
	   {
	        ans*=m;
	        if(ans>x)
	            return 2;
	   }
	   return (ans==x)?1:0;
	    
	}
	int NthRoot(int n, int m)
	{
	    // 0 denotes mid^n is less than m
	    // 1 denotes mid^n is equal to m
	    // 2 denotes mid^n is greater than m
	    int low=1, high=m;
	    int mid=(low + high)/2;
	    while(low<=high)
	    {
	        mid=(low+high)/2;
	        int ans= power(mid,n,m);
	        if(ans ==1)
	            return mid;
	        else if(ans==0)
	            low = mid +1;
	        else
	            high= mid-1;
	    }
	    return -1;
	    
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends