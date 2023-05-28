//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        long long s=0, n=v.size(),e =n-1, mid=0, temp=0;
        pair<long, long> p ={-1,-1};
        while(s<=e and v[mid]!=x)
        {
            mid=(s+e)/2;
            if(v[mid]<x)
                s=mid+1;
            else if(v[mid]>x)
                e=mid-1;
        }
        if(v[mid]==x)
            temp=mid;
        else
            return p;
        
        s=0;
        e=temp-1;
        while(s<=e)
        {
            mid=(s+e)/2;
            if(v[mid]<x)
                s=mid+1;
            else if(v[mid]==x)
                e=mid-1;
        }
        p.first=s;
        
        s=temp;
        e=n-1;
        while(s<=e)
        {
            mid=(s+e)/2;
            if(v[mid]==x)
                s=mid+1;
            else if(v[mid]>x)
                e=mid-1;
        }
        p.second=e;
        
        return p;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends