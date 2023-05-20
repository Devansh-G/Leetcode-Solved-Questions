//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void fun(vector<vector<int>> &b, vector<int> &v, vector<int> &arr, int index)
    {
        if(index > arr.size())
            return;
        b.push_back(v);
        for(int i = index; i<arr.size(); i++)
        {
            if(i!=index && arr[i]==arr[i-1])
                continue;
            v.push_back(arr[i]);
            fun(b,v,arr,i+1);
            v.pop_back();
        }
        return;
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        vector<vector<int>> b;
        vector<int> v;
        sort(arr.begin(),arr.end());
        fun(b,v,arr,0);
        return b;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends