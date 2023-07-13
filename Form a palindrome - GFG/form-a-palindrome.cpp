//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
   int lcs(string a, string b)
    {
        int n= a.length();
        vector<int> curr(n+1,0),prev(n+1,0);
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            prev=curr;
            for(int j=1;j<=n;j++)
            {
                if(a[i-1]==b[j-1])
                    curr[j]= prev[j-1]+1;
                else
                    curr[j]=max(prev[j],curr[j-1]);
            }
        }
        return curr[n];
    }
    int countMin(string str){
    //complete the function here
    //calculating longest palindromic subsequence
        string s=str;
        reverse(s.begin(), s.end());
        int len = lcs(s,str);
        //cout<<s.length()<<" "<<len;
        return s.length()-len;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends