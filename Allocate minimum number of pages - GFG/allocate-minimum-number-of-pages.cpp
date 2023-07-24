//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    int fun(int arr[], int n, int maxi)
    {
        int count = 0, sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum > maxi)
            {
                sum = arr[i];
                count++;
            }
        }
        return count + 1;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        int low = *max_element(A, A+N);
        int high = accumulate(A, A+N, 0);
        if(M>N)
            return -1;
        if(N==M)
            return low;
        while(low<=high)
        {
            int mid  = (low + high)/2;
            int students = fun(A, N, mid);
            if(students > M)
                low = mid + 1;
            else
                high = mid - 1;
            
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends