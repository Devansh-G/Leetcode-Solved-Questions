//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    int getCount(int x, int y, int n) {
        // code here
        int count=0;
        bool arr[n+1]={0};
        int a= min(x,y), b= max(x,y);
        if(a>n)
            return 0;
        arr[a]=true;
        count++;
        if(b<n &&!arr[b])
        {
            arr[b]=true;
            count++;
        }
        for(int i=min(x,y);i<=n;i++)
        {
            if(arr[i])
            {
                if(i+a <=n)
                {
                    if(!arr[i+a])
                        count++;
                    arr[i+a]=true;
                    if(i+b<=n)
                    {
                        if(!arr[i+b])
                            count++;
                        arr[i+b]=true;
                    }
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int x,y,n;
        
        cin>>x>>y>>n;

        Solution ob;
        cout << ob.getCount(x,y,n) << endl;
    }
    return 0;
}
// } Driver Code Ends