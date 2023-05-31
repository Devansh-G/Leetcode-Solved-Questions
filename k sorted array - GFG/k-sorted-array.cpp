//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int search(int a[], int &n, int &target)
    {
        int s=0,e=n-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(a[mid]==target)
                return mid;
            else if(a[mid]>target)
                e=mid-1;
            else
                s=mid+1;
        }
        return -1;
    }
    string isKSortedArray(int arr[], int n, int k)
    {
        //code here.
        int a[n];
        for(int i=0;i<n;i++)
        {
            a[i] = arr[i];
        }
        sort(a,a+n);
        // for(int i=0;i<n;i++)
        // {
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<n;i++)
        {
            if(abs(i - search(a,n,arr[i]))>k)
            {
                //cout<<i<<" ";
                return "No";
            }
        }
        return "Yes";
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>k;
	    Solution ob;
	cout <<ob.isKSortedArray(arr, n, k)<<endl;
	}
	return 0;	 
}
// } Driver Code Ends