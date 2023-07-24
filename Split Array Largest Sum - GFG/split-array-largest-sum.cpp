//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(int arr[], int &N, int &cap)
    {
        int count = 0, sum = 0;
        for(int i=0;i<N;i++)
        {
            sum += arr[i];
            if(sum > cap)
            {
                count++;
                sum = arr[i];
            }
        }
        return count + 1;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int low = *max_element(arr, arr+N);
        int high = accumulate(arr, arr+N, 0);
        while(low <=high)
        {
            int mid =(low + high)/2;
            int partitions = fun(arr,N,mid);
            if(partitions > K)
                low = mid + 1;
            else
                high = mid -1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends