//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void fun(vector<int> &v, vector<int> &arr,int i, int &ans, int &N)
    {
        if(i==N)
        {
            v.push_back(ans);
            return;
        }
        
        ans+=arr[i];
        fun(v,arr,i+1,ans,N);
        
        ans-=arr[i];
        fun(v,arr,i+1,ans,N);
        return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> v;
        int ans=0;
        fun(v,arr,0,ans,N);
        sort(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends