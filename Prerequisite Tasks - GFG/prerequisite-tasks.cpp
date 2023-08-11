//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	    vector<int> adj[N];
	    for(auto it : prerequisites)
	    {
	        int course = it.first;
	        int preCourse = it.second;
	        
	        adj[preCourse].push_back(course);
	    }
	    
	   vector<int> indegrees(N,0);
	   for(int i=0 ;i< N; i++)
	   {
	       for(auto node : adj[i])
	           indegrees[node]++;
	   }
	   
	    int count=0;
	    queue<int> q;
	    for(int i =0 ; i<N ; i++)
	    {
	        if(indegrees[i] == 0)
	            q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for(auto adjacentNode : adj[node])
            {
                indegrees[adjacentNode]--;
                if(indegrees[adjacentNode]==0)
                    q.push(adjacentNode);
            }
        }
        
        if(count == N)
            return true;
        return false; 
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends