//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int &n, int &m, int index)
    {
        if(index==word.length())
            return true;
        int ax[]={0,0,1,-1};
        int ay[]={1,-1,0,0};
        for(int k=0;k<4;k++)
        {
            int nx=i+ax[k], ny=j+ay[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny]==word[index])
            {
                char ch=board[i][j];
                board[i][j]='0';
                if(dfs(board, word, nx, ny, n, m,index + 1))
                    return true;
                board[i][j]=ch;
            }
        }
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size(), m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    char ch=board[i][j];
                    board[i][j]='0';
                    if(dfs(board, word, i, j, n, m,1))
                        return true;
                    board[i][j]=ch;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends