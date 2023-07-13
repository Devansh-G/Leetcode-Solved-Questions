//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        vector<string> v;
        unordered_map<string, int> m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        int freq=0;
        for(auto it=m.begin() ; it!=m.end() ; it++)
        {
            if(it->second>freq)
            {
                freq=it->second;
                v.clear();
                v.push_back(it->first);
            }
            if(it->second==freq)
                v.push_back(it->first);
        }
        
        sort(v.begin(), v.end());
        
        while(v.size()!=1)
            v.pop_back();
        string s="";
        while(freq>0)
        {
            s+= freq%10 +'0';
            freq/=10;
        }
        reverse(s.begin(),s.end());
        v.push_back(s);
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends