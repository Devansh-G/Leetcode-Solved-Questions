//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sentencePalindrome(string s) 
	{
	    // code here 
	    int start=0, end=s.length()-1, n=s.length();
	    while(start<=end)
	    {
	        while((s[start]<'a' || s[start]>'z') && start<n)
	            start++;
	       while((s[end]<'a' || s[end]>'z') && end>=0)
	            end--;
	       if(s[start++]!=s[end--])
	            return false;
	    }
	    return true;
	}
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        Solution ob;
        cout<<ob.sentencePalindrome(str)<<endl;
    }
    return 0;
}  


// } Driver Code Ends