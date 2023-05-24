//{ Driver Code Starts
//Initial template for C++
 
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int minLength(string s, int n) {
        // code here
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
                st.push(s[i]);
            else
            {
                int check=0;
                switch(s[i])
                {
                    case '1' : 
                        if(st.top()=='2')
                            check++;
                        break;
                    case '2' :
                        if(st.top()=='1')
                            check++;
                        break;
                    case '3' : 
                        if(st.top()=='4')
                            check++;
                        break;
                    case '4' :
                        if(st.top()=='3')
                            check++;
                        break;
                    case '5' : 
                        if(st.top()=='6')
                            check++;
                        break;
                    case '6' :
                        if(st.top()=='5')
                            check++;
                        break;
                    case '7' : 
                        if(st.top()=='8')
                            check++;
                        break;
                    case '8' :
                        if(st.top()=='7')
                            check++;
                        break;
                    case '9' : 
                        if(st.top()=='0')
                            check++;
                        break;
                    case '0' :
                        if(st.top()=='9')
                            check++;
                        break;
                }
                if(check)
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        return st.size();
    } 
};


//{ Driver Code Starts.

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        Solution obj;
        cout << obj.minLength(s, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends