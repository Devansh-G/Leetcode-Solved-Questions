//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        int left=0, ans=0;
        int m[26]={0};
        for(int i=0;S[i]!='\0';i++)
        {
            m[S[i]-'a']++;
            while(m[S[i]-'a']>1)
            {
                m[S[left]-'a']--;
                left++;
            }
            ans = max(ans, i-left+1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends