//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
    int low=0, high = n-1;
        while(low<=high)
        {
            int mid=(low + high)/2;
            if(a[mid] - mid -a[0] >= k)
                high = mid - 1;
            else
                low = mid + 1;
        }
        if(k + high + a[0] > a[n-1])
            return -1;
        return k + high + a[0];
}