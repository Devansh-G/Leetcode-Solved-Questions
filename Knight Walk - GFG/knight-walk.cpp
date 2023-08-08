//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    queue<pair<pair<int, int>,int>> q;
	    vector<vector<int>> dist(N + 1, vector<int> (N + 1,-1));
	    
	    q.push({{KnightPos[0], KnightPos[1]},0});
	    dist[KnightPos[0]][KnightPos[1]] = 0;
	    int ax[] ={ -1, 1, 2, 2, -1, 1, -2, -2};
	    int ay[] ={ 2, 2, 1, -1, -2, -2, 1, -1};
	    while(!q.empty())
	    {
	        int x = q.front().first.first;
	        int y = q.front().first.second;
	        int distance = q.front().second;
	        q.pop();
	        
	        if(x== TargetPos[0] and y== TargetPos[1])
	            return distance;
	        for(int k = 0 ; k<8 ; k++)
	        {
	            int nx = x + ax[k] , ny = y + ay[k];
	            if(nx > 0 and nx <=N and ny > 0 and ny <= N and dist[nx][ny] == -1)
	            {
	                q.push({{nx,ny}, distance + 1});
	                dist[nx][ny] = distance + 1;
	            }
	        }
	    }
	    return dist[TargetPos[0]][TargetPos[1]];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends