//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int fun(int *arr, int n, int cap)
    {
        int count = 0, sum=0;
        for(int i=0;i<n;i++)
        {
            sum +=arr[i];
            if(sum > cap)
            {
                count++;
                sum = arr[i];
            }
        }
        return count + 1;
    }
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int low = *max_element(arr, arr + N);
        int high = accumulate(arr, arr + N, 0);
        int mid =(low + high)/2;
        while(low<=high)
        {
            mid = (low + high)/2;
            int num = fun(arr, N, mid);
            if(num <= D)
                high = mid-1;
            else
                low = mid + 1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends