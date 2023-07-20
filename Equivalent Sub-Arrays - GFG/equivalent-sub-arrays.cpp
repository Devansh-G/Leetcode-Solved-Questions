//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        set<int> st;
        unordered_map<int, int> freq;
        for(int i=0;i<n;i++)
            st.insert(arr[i]);
        
        int k=st.size();                        //Number of distinct elements in the original array
        int left=0, right=0, count=0;
        while(right<n)
        {
            freq[arr[right]]++;
            
            while(freq.size()==k)
            {
                count+=(n-right);
                if(freq[arr[left]]>1)
                    freq[arr[left]]--;
                else
                    freq.erase(arr[left]);
                left++;
            }
            right++;
        }
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
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends