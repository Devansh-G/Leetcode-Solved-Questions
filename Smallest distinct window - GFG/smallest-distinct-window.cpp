//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char, int> freq;
        for(auto ch:str)
            freq[ch]++;
        int k=freq.size(), left=0;
        int len=INT_MAX;
        freq.clear();
        for(int i=0;i<str.length();i++)
        {
            freq[str[i]]++;
            while(freq.size()==k)
            {
                len=min(len,i - left + 1);
                if(freq[str[left]]>1)
                    freq[str[left]]--;
                else
                    freq.erase(str[left]);
                left++;
            }
        }
        return len;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends