//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        int n = wordList.size(), m = startWord.length();
        unordered_set<string> st;
        for(int i = 0;i<n;i++)
            st.insert(wordList[i]);
        
        queue<pair<string, int>> q;
        q.push({startWord,1});
        while(!q.empty())
        {
            string s = q.front().first;
            int path = q.front().second;
            
            q.pop();
            if(s == targetWord)
                return path;
            for(int i = 0; i<m ; i++)
            {
                char ch = s[i];
                for(int j = 0; j<26 ; j++)
                {
                    if(j == ch - 'a')
                        continue;
                    s[i] = j + 'a';
                    if(st.find(s)!=st.end())
                    {
                        st.erase(s);
                        q.push({s,path + 1});
                    }
                }
                s[i] = ch;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends