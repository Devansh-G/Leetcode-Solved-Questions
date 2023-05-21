//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    bool isPrime(long long n)
    {
        if(n==1)
            return false;
        if(n==2 || n==3)
            return true;
        for(long long i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    int maxUniquePrimeFactors(long long N) {
        // code here
        long long ans=0, temp=1;
        for(long long i=2;temp<=N;i++)
        {
            if(isPrime(i))
            {
                ans++;
                temp*=i;   
            }
        }
        return ans-1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.maxUniquePrimeFactors(N) << endl;
    }
    return 0;
}
// } Driver Code Ends