//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int &sr, int& sc, int& initial, int& newColor, int ax[], int ay[], vector<vector<int>>& image, vector<vector<int>>& ans)
    {
        ans[sr][sc] = newColor;
        for(int k=0; k<4; k++)
        {
            int nx = sr + ax[k];
            int ny = sc + ay[k];
            if(nx>=0 and nx<image.size() and ny>=0 and ny<image[0].size() and image[nx][ny] == initial and ans[nx][ny] != newColor)
                dfs(nx, ny, initial , newColor, ax, ay, image, ans);
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>> ans;
        ans = image;
        int initial = image[sr][sc];
        if(initial == newColor)
            return ans;
        int ax[4] = { 0, 0, -1, 1};
        int ay[4] = { -1, 1, 0, 0};
        dfs(sr, sc, initial, newColor, ax, ay, image, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends