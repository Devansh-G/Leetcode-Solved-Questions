//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int lcs(string &a, string &b)
    {
        int n= a.length(),m=b.length();
        vector<int> curr(m+1,0),prev(m+1,0);
        for(int i=1;i<=n;i++)
        {
            prev=curr;
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                    curr[j]= prev[j-1]+1;
                else
                    curr[j]=max(prev[j],curr[j-1]);
                //cout<<curr[j]<<" ";
            }
            //cout<<endl;
        }
        return curr[m];
    }
	int findMinCost(string X, string Y, int costX, int costY)
	{
	    // Your code goes here
	    int len=lcs(X,Y);
	    return costX*(X.length()-len) + costY*(Y.length()-len);
	}
  

};
	

//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
       	string x, y;
       	cin >> x >> y;
        
       	int costX, costY;
       	cin >> costX >> costY;

        

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends