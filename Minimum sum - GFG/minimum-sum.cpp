//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        sort(arr, arr+n, greater <int> () );
        string s="";
        int carry=0;
        for(int i=0;i<n;i+=2)
        {
            
            int temp = arr[i];
            if(i+1<n)
                temp+=arr[i+1];
            temp+=carry;
            carry=temp/10;
            temp%=10;
            s+=temp + '0';
        }
        if(carry!=0)
            s+=carry + '0';
        int len=s.length();
        
        while(s[len-1]=='0'  && len>1)
        {
            s.pop_back();
            len--;
        }
       
        reverse(s.begin(),s.end());
        
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends