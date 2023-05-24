//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        vector<int> v;
        for(int i=0;i<N;i++)
        {
            if(v.empty() || asteroids[i]>0 || v.back()*asteroids[i]>1)
                v.push_back(asteroids[i]);
            else
            {
                int temp = asteroids[i];
                while(!v.empty() && (v.back()>0 && temp<0))
                {
                    if(abs(v.back()) < abs(temp))
                        v.pop_back();
                    else if(abs(v.back()) > abs(temp))
                        break;
                    else
                    {
                        v.pop_back();
                        temp=0;
                        break;
                    }
                }
                if(temp==0)
                    continue;
                if(v.empty() || v.back() * temp > 0 )
                    v.push_back(temp);
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends