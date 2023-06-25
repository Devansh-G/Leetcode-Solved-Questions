//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        int nx[]={ 0, 1, 0, -1};
        int ny[]={ 1, 0, -1, 0};
        
        int n=matrix.size(), m=matrix[0].size();
        int i=0, j=0, dir_index=0;
        while(i<n and j<m and i>=0 and j>=0)
        {
            if(matrix[i][j]==0)
            {
                i+=nx[dir_index];
                j+=ny[dir_index];
            }
            else
            {
                matrix[i][j]=0;
                dir_index++;
                dir_index%=4;
                i+=nx[dir_index];
                j+=ny[dir_index];
            }
        }
        i-=nx[dir_index];
        j-=ny[dir_index];
        return make_pair(i,j);
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends