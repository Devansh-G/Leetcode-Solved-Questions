//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        int row_start = 0, row_end = n-1, col_start=0, col_end = m-1;
        vector<int> v;
        for(int i = col_start;i<=col_end;i++)
            v.push_back(matrix[row_start][i]);
        row_start++;
        
        for(int i = row_start ; i<= row_end; i++)
            v.push_back(matrix[i][col_end]);
        col_end--;
        
        if(row_start <= row_end)
        {
            for(int i= col_end; i>= col_start; i --)
                v.push_back(matrix[row_end][i]);
            row_end--;
        }
        
        if(col_start <= col_end)
        {
            for(int i= row_end; i>=row_start; i--)
                v.push_back(matrix[i][col_start]);
        }
        return v;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends