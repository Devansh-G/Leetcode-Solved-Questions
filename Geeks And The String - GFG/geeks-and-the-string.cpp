//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        string str="";
        int k=0;
        for(int i=0;s[i]!='\0';i++)
        {
            if(str=="")
            {
                str+=s[i];
                k++;
            }
            else if(str[k-1]==s[i])
            {
                k--;
                str.pop_back();
            }
            else
            {
                str+=s[i];
                k++;
            }
        }
        if(k==0)
            return "-1";
        return str;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends