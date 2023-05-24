//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.first<b.first;
    }
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            pair<int, int> p={price[i],i+1};
            v.push_back(p);
        }
        sort(v.begin(),v.end(), cmp);
        int i=0;
        int count=0;
        // for(int i=0;i<n;i++)
        // {
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }
        // cout<<endl;
        while(k>=0 && i<n)
        {
            if((v[i].first * v[i].second) <=k)
            {
                count+=v[i].second;
                k-=(v[i].first * v[i].second);
                i++;
            }
            else if(v[i].first > k)
                break;
            else
            {
                count+=(k/v[i].first);
                k-=(k/v[i].first) * v[i].first;
                i++;
            }
            //cout<<"count = "<<count<<" , k = "<<k<<endl;
        }
        if(k<0) 
            count--;
        return count;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends