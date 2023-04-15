//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void fun(vector<string> &v, string &s, int index)
	    {
	        if(index == s.length()-1)
	        {
	            v.push_back(s);
	            return;
	        }
	        for(int i=index ; i<s.length(); i++)
	        {
	            if(i>index && s[i]==s[i-1])
	                continue;
	            swap(s[i],s[index]);
	            fun(v,s,index + 1);
	            swap(s[i],s[index]);
	        }
	        return ;
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    int index=0;
		    vector<string> v;
		    fun(v, S, index);
		    sort(v.begin(), v.end());
		    return v;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends