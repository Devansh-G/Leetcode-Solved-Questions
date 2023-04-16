//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(vector<string> &v, string &s, int i, int j, vector<vector<int>> & arr, int &n)
    {
        if(i==n-1 && j==n-1)
        {
            v.push_back(s);
            return;
        }
        
        // int ax[] = { 0, 0, 1, -1};
        // int ay[] = { 1, -1, 0, 0};
        // char letter[] ={ 'R' , 'L' , 'D' , 'U' };
        
        int ax[] = { 1, 0, 0, -1};
        int ay[] = { 0, -1, 1, 0};
        char letter[] ={ 'D' , 'L' , 'R' , 'U' };
        for(int k=0;k<4;k++)
        {
            int nx = i+ ax[k] , ny = j + ay[k];
            if(nx>=0 && nx<n && ny>=0 && ny <n && arr[nx][ny]==1)
            {
                arr[nx][ny]=0;
                s+=letter[k];
                dfs(v,s,nx,ny,arr,n);
                arr[nx][ny]=1;
                s.pop_back();
            }
        }
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string s="";
        vector<string> v;
        if(m[0][0]==0)
            return v;
        m[0][0]=0;
        dfs(v,s,0,0,m,n);
        //sort(v.begin(),v.end());        // We wont need to sort this array if we took the lexiographical order from the start
        // INSTEAD OF LINE 21-23 WE WRITE LINE 25 - 27
        return v;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends