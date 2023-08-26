//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    void dfs(string last, vector<string> &v, string &beginWord)
    {
        
        int len = mp[last];
        if(last == beginWord)
        {
            reverse(v.begin(), v.end());
            ans.push_back(v);
            reverse(v.begin(), v.end());
            return;
        }
        for(int i = 0 ;i<beginWord.size(); i++)
        {
            char ch = last[i];
            for(char j = 'a';j<='z';j++)
            {
                if(j==ch)
                    continue;
                last[i] = j;
                if(mp.find(last)!=mp.end())
                {
                    if(mp[last] == len - 1)
                    {
                        v.push_back(last);
                        dfs(last, v, beginWord);
                        v.pop_back();
                    }
                }
            }
            last[i] = ch;
        }
        return ;
    }
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        // unordered_set<string> st(wordList.begin(), wordList.end());
        // queue<vector<string>> q;
        // vector<vector<string>> ans;
        // q.push({beginWord});
        // if(st.find(beginWord)!=st.end())
        //     st.erase(beginWord);
        // int n;
        // bool flag = false;
        // while(!q.empty())
        // {
        //     vector<string> v = q.front();
        //     for(auto stri:v)
        //         cout<<stri<<" ";
        //     cout<<endl;
        //     q.pop();
        //     string s = v.back();
        //     if(flag and v.size()>n)
        //     {
                
        //     }
        //     if(s== endWord)
        //     {
        //         ans.push_back(v);
        //         // int n = v.size();
        //         // while(!q.empty() and q.front().size()==n)
        //         // {
        //         //     vector<string> v = q.front();
        //         //     q.pop();
        //         //     string s = v.back();
        //         //     if(s==endWord)
        //         //         ans.push_back(v);
        //         // }
        //         // return ans;
        //         flag = true;
        //         n = v.size();
        //     }
        //     vector<string> temp;
        //     for(int i = 0; i<s.size(); i++)
        //     {
        //         char ch = s[i];
        //         for(char j = 'a' ; j<='z' ; j++)
        //         {
        //             if(ch==j)
        //                 continue;
        //             s[i] = j;
        //             if(st.find(s) != st.end())
        //             {
        //                 temp.push_back(s);
        //                 v.push_back(s);
        //                 q.push(v);
        //                 v.pop_back();
        //             }
        //             s[i] = ch;
        //         }
        //     }
        //     for(string str : temp)
        //     {
        //         st.erase(str);
        //     }
        // }
        // return {};
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;
        st.erase(beginWord);
        while(!q.empty())
        {
            string last = q.front();
            q.pop();
            if(last == endWord)
                break;
            string s = last;
            int steps = mp[last];
            for(int i = 0 ; i<beginWord.length(); i++)
            {
                char ch = s[i];
                for(char j ='a' ; j<='z'; j++)
                {
                    if(ch == j)
                        continue;
                    s[i] = j;
                    if(st.find(s)!=st.end())
                    {
                        st.erase(s);
                        mp[s] = steps + 1;
                        q.push(s);
                    }
                }
                s[i] = ch;
            }
        }
        vector<string> v;
        v.push_back(endWord);
        dfs(endWord, v, beginWord);
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends