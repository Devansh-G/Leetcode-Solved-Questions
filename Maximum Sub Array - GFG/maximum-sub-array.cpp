//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    
	    //Kadane's Algorithm
	    vector<int> v;
	    int start=-1, end=-1,left=0;
	    long long Ksum=0, currSum=0;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]<0)
    	        currSum=0;
    	    else
    	    {
    	        if(currSum==0)
    	            left=i;
    	        currSum+=a[i];
    	        if(currSum > Ksum)
    	        {
    	            Ksum=currSum;
    	            start=left;
    	            end=i;
    	        }
    	        else if(currSum == Ksum and (end - start) < (i-left))
    	        {
    	            start=left;
    	            end=i;
    	        }
    	    }
	    }
	    
	    if(start==-1)
	    {
	        v.push_back(-1);
	        return v;
	    }
	    for(int i=start; i<=end; i++)
	        v.push_back(a[i]);
	   return v;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends