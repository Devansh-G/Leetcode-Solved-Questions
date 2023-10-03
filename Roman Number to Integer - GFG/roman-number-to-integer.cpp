//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int temp = 0, ans=0;
        temp = mp[str[0]];
        for(int i = 1; i<str.length(); i++)
        {
            if(mp[str[i-1]] < mp[str[i]])
            {
                ans += mp[str[i]] - temp;
                temp = 0;
            }
            else if(mp[str[i-1]] == mp[str[i]])
                temp+= mp[str[i]];
            else
            {
                ans+=temp;
                temp = mp[str[i]];
            }
            //cout<<temp<<" "<<ans<<endl;
        }
        return ans + temp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends