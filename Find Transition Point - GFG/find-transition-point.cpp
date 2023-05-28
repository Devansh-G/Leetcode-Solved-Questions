//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    // code here
    int count=0;
    int s=0,e=n-1;
    while(s<=e and arr[s]==0)
    {
        int mid = (s+e)/2;
        if(arr[mid])
            e=mid-1;
        else
            s=mid+1;
    }
    if(s==n)
        return -1;
    return s;
}