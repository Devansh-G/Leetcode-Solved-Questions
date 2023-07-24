//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int total = 0;
        int maxSum =0, mx = arr[0];
        for(int i=0;i<num;i++)
        {
            maxSum += arr[i];
            mx= max(mx, maxSum);
            if(maxSum<0)
                maxSum =0;
        }
        //cout<<mx<<endl;
    
        int mn= arr[0], minSum =0;
        for(int i=0;i<num;i++)
        {
            minSum +=arr[i];
            mn =  min(mn, minSum);
            total+=arr[i];
            if(minSum>0)
                minSum = 0;
        }
        //cout<<mn<<endl;
        if(total==mn)
            return mx;
        return max(mx, total - mn);
        
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends