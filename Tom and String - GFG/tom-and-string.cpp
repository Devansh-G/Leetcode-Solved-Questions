//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int hashString(string S) {
        // Code Here
        long long int ans=0;
        int n=0;
        int ind=0;
        for(int i=0;S[i]!='\0';i++)
        {
            if(S[i]==' ')
            {
                n++;
                ind=-1; // ind is given the value of -1 because before the next iteration ind++ will be done
            }
            else if(S[i]>='a'  and S[i]<='z')
                ans+= ind + S[i] - 'a';
            else if(S[i]>='A'  and S[i]<='Z')
                ans+= ind + S[i] - 'A' +36;
            else if(S[i]=='0')
                ans+=ind + 35;
            else
                ans+= ind + S[i] - '1' + 26;
            ind++;
            //cout<< ans<<endl;
        }
        return ans * (n+1); 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.hashString(s) << endl;
    }
    return 0;
}
// } Driver Code Ends