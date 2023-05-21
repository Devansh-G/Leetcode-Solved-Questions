//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    bool isPrime(int n)
    {
        if(n==2 || n==3)
            return true;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    long long int primeProduct(int N){
        //code here
        long long ans=1;
        for(int i=1;i<=sqrt(N);i++)
        {
            if(N%i==0)
            {
                if(isPrime(i))
                    ans*=i;
                if(i*i != N && isPrime(N/i))
                    ans*=N/i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.primeProduct(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends