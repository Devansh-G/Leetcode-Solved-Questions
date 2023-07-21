//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    bool equal(vector<int> &m1, vector<int> &m2)
    {
        for(int i=0;i<26;i++)
        {
            if(m1[i]>m2[i])
                return false;
        }
        return true;
    }
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int> m1(26,0), m2(26,0);
        for(auto &ch: p)
            m1[ch-'a']++;
            
        int len=INT_MAX;
        int start=-1, end=-1, left=0;
        
        for(int i=0;i<s.length();i++)
        {
            m2[s[i]-'a']++;
            while(equal(m1,m2))
            {
                if(len > i-left+1)
                {
                    start=left;
                    end=i;
                    len=min(len,i-left+1);
                }
                
                m2[s[left]-'a']--;
                left++;
            }
        }
        // cout<<"start = "<<start<<endl;
        // cout<<"end = "<<end<<endl;
        // cout<<"length = "<<len<<endl;
        
        if(start==-1)
            return "-1";
            
        string ans="";
        for(int i=start;i<=end;i++)
            ans+=s[i];
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
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends