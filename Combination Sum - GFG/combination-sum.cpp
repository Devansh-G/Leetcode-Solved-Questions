//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void fun(vector<vector<int>> &b, vector<int> &v, int index, vector<int> &arr, int &target)
    {
        if(target<0 || index>= arr.size())
            return;
        if(target==0)
        {
            b.push_back(v);
            return;
        }
        for(int i=index;i<arr.size();i++)
        {
            if(i!=index && arr[i]== arr[i-1])
                continue;
            target-=arr[i];
            v.push_back(arr[i]);
            fun(b,v,i, arr, target);
            v.pop_back();
            target+=arr[i];
        }   
            //fun(b,v,index + 1,arr, target);
        
        
        return;
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>> b;
        vector<int> v;
        sort(A.begin(),A.end());
        fun(b,v,0,A,B);
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
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
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