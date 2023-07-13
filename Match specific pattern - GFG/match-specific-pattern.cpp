//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<string> findMatchedWords(vector<string> dict,string pattern);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> s(n);
		for(int i=0;i<n;i++)
		    cin>>s[i];
		
		string tt;
		cin>>tt;
		
		vector<string> res = findMatchedWords(s,tt);
        sort(res.begin(),res.end());
		for(int i=0;i<res.size();i++)
		    cout<<res[i]<<" ";
		cout<<endl;
		
	}
}
// } Driver Code Ends


/* The function returns a  vector of strings 
present in the dictionary which matches
the string pattern.
You are required to complete this method */
vector<string> findMatchedWords(vector<string> dict,string pattern)
{
       //Your code here
       vector<string> ans;
       int n=pattern.size();
       for(int i=0;i<dict.size();i++)
       {
           if(dict[i].length()!=n)
                continue;
           vector<int> arr(26,-1), arr2(26,-1);
           bool temp=true;
           for(int j=0;j<n;j++)
           {
                if(arr[dict[i][j]-'a']==-1 && arr2[pattern[j]-'a']==-1)
                {
                    arr[dict[i][j] -'a'] = pattern[j]-'a';
                    arr2[pattern[j] -'a'] = dict[i][j]-'a';
                }
                    
                else if(arr[dict[i][j]-'a']==pattern[j]-'a' and arr2[pattern[j]-'a']==dict[i][j]-'a')
                    continue;
                else
                    temp=false;
                // if(i==0)
                // {if(temp==false)
                //     cout<<"1"<<endl;
                // else
                //     cout<<"0"<<endl;}
           }
           if(temp)
                ans.push_back(dict[i]);
       }
       return ans;
}