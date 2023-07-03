//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int firstbit(long long int n)
	{
	    int ans=0;
	    while(n>0)
	    {
	        ans++;
	        n/=2;
	    }
	    return ans;
	}
	long long int findBitwiseOR(long long int L, long long int R){
	    //complete the function here
	    int n=firstbit(L) , m=firstbit(R);
	    long long mask=0;
	    if(n!=m)
	    {
	        
	        while(m--)
	        {
	            mask=mask<<1;
	            mask+=1;
	        }
	        return mask;
	    }
	    long long int temp=L^R;
	    int p= firstbit(temp);
	    while(p--)
	    {
	        mask=mask<<1;
	        mask+=1;
	    }
	    return L|mask;
	    
	}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        long long L, R;
        cin >> L >> R;
        Solution ob;
        cout << ob.findBitwiseOR(L, R) << endl;
    }
    return 0;
}


// } Driver Code Ends