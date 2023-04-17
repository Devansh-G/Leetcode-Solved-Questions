//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        int fact=1;
        string s="";
        vector<int> nums;
        for(int i=1;i<n;i++)
        {
            fact*=i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k-=1;
        while(nums.size()>1)
        {
            s+=nums[k/fact] +'0';
            nums.erase(nums.begin() + k/fact);
            k%=fact;
            fact/=nums.size();
        }
        s+=nums[0] +'0';
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends