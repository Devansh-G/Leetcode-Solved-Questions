//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void fun(vector<string> &v, int index, string &s)
    {
        if(index == s.length())
        {
            v.push_back(s);
            return;
        }
        for(int i= index ; i< s.length(); i++)
        {
            swap(s[index] , s[i]);
            fun(v,index + 1, s);
            swap(s[index] , s[i]);
        }
        return ;
    }
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> v;
        fun(v,0,S);
        sort(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends