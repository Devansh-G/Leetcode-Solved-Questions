//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    //Write your code here..
    int n=price.size();
    vector<vector<int>> curr(2, vector<int> (3,0)), next(2, vector<int> (3,0));
    //for memoization and tabulation see 123. Best Time to Buy and Sell Stock III on leetode
    for(int i=n-1;i>=0;i--)
    {
        next=curr;
        for(int buy=0;buy<2;buy++)
        {
            for(int t=0;t<2;t++)
            {
                if(buy)
                    curr[buy][t] = max(next[0][t] - price[i], next[1][t]);
                else
                    curr[buy][t] = max(next[1][t+1] + price[i], next[0][t]);
            }
        }
    }
    return curr[1][0];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends