//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
  long long sum(int n, vector<int> &arr, vector<int> &dp, vector<int> &check)
    {
        if(n<0)
            return 0;
        if(check[n]!=0)
            return dp[n];
        long long pick = arr[n] + sum(n-1, arr, dp , check);
        long long not_pick = 0;
        if(n>0)
            not_pick = arr[n-1] + sum(n-2, arr, dp , check);
        check[n]=1;
        return dp[n] = max(pick, not_pick);
    }
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<int> dp(N,0), check(N,0);
        return sum(N-1, A,dp,check);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends