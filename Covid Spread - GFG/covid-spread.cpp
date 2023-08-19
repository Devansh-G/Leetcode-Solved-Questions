//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int n = hospital.size();
        int m = hospital[0].size();
        
        queue<pair<int,pair<int, int>>> q;
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        
        for(int i = 0 ; i<n ;i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(hospital[i][j] == 2)
                    q.push({0,{i,j}});
            }
        }
        
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        int ans = 0;
        while(!q.empty())
        {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int distance = q.front().first;
            q.pop();
            dist[x][y] = distance;
            
            for(int k = 0; k<4 ;k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx>=0 and nx<n and ny>=0 and ny<m and hospital[nx][ny]==1 and distance + 1 < dist[nx][ny])
                {
                    q.push({distance + 1, {nx,ny}});
                    ans = max(ans, distance+1);
                }
            }
        }
        for(int i = 0; i< n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(hospital[i][j] == 1 and dist[i][j] == 1e9)
                    return -1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends