//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // bool is_safe(int n, bitset<n> &c, bitset<n> &r, bitset<2*n> &r_diagonal, bitset<2*n> &l_diagonal, int i, int j)
    // {
    //     if(c[i]==1)
    //         return false;
    //     if(r[j]==1)
    //         return false;
    //     if(r_diagonal[i+j]==1)
    //         return false;
    //     if(l_diagonal[j-i]==1)
    //         return false;
    // }
    // bool canwesolve(vector<vector<int>> b, vector<int> v, int n, bitset<n> &c, bitset<n> &r, bitset<2*n> &r_diagonal, bitset<2*n> &l_diagonal, int i)
    // {
    //     if(i==n)
    //     {
    //         b.push_back(v);
    //         return false;
    //     }
    //     for(int x=0;x<n;x++)
    //     {
    //         if(is_safe(n,c,r,r_disagonal,l_diagonal,i,x))
    //         {
    //             v.push_back(x+1);
    //             if(canwesolve(b,v,n,c,r,r_disaognal,l_diagonal,i+1));
    //                 return true;
    //             v.pop_back();
    //         }
    //     }
    //     return false;
    // }
    
    
    
    // bool is_safe(int n, vector<int> &r, vector<int> &r_diagonal, vector<int> &l_diagonal, int i, int j)
    // {
    //     if(r[j]==1)
    //         return false;
    //     if(r_diagonal[i+j]==1)
    //         return false;
    //     if(l_diagonal[j-i+n]==1)
    //         return false;
    //     return true;
    // }
    // bool canwesolve(vector<vector<int>> &b, vector<int> &v, int n, vector<int> &r, vector<int> &r_diagonal, vector<int> &l_diagonal, int i)
    // {
        
    //     if(i==n)
    //     {
    //         b.push_back(v);
    //         v.clear();
    //         return false;
    //     }
    //     for(int j=0;j<n;j++)
    //     {
    //         if(is_safe(n,r,r_diagonal,l_diagonal,i,j))
    //         {
    //             v.push_back(j+1);
    //             r[j]=1;
    //             r_diagonal[i+j]=1;
    //             l_diagonal[j-i+n]=1;
    //             if(canwesolve(b,v,n,r,r_diagonal,l_diagonal,i+1))
    //                 return true;
    //             else
    //             {
    //                 r[j]=0;
    //                 r_diagonal[i+j]=0;
    //                 l_diagonal[j-i+n]=0;
    //                 v.pop_back();
    //             }
    //         }
    //     }
    //     return false;
    // }
    
    
    bool is_safe(int n, bool r[], bool r_diagonal[], bool l_diagonal[], int i, int j)
    {
        if(r[j]==true)
            return false;
        if(r_diagonal[i+j]==true)
            return false;
        if(l_diagonal[j-i+n]==true)
            return false;
        return true;
    }

    // void canwesolve(vector<vector<int>> &b, vector<int> &v, int n, bool r[], bool r_diagonal[], bool l_diagonal[], int i)
    // {
    //     if(i==n)
    //     {
    //         b.push_back(v);
    //         return ;
    //     }
    //     for(int j=0;j<n;j++)
    //     {
    //         if(is_safe(n,r,r_diagonal,l_diagonal,i,j))
    //         {
    //             v.push_back(j+1);
    //             r[j]=true;
    //             r_diagonal[i+j]=true;
    //             l_diagonal[j-i+n]=true;
                
    //             canwesolve(b,v,n,r,r_diagonal,l_diagonal,i+1);
                
    //             r[j]=false;
    //             r_diagonal[i+j]=false;
    //             l_diagonal[j-i+n]=false;
    //             v.pop_back();
    //         }
    //     }
    //     return ;
    // }
    
    bool canwesolve(vector<vector<int>> &b, vector<int> &v, int n, bool r[], bool r_diagonal[], bool l_diagonal[], int i)
    {
        if(i==n)
        {
            b.push_back(v);
            return false;
        }
        for(int j=0;j<n;j++)
        {
            if(is_safe(n,r,r_diagonal,l_diagonal,i,j))
            {
                v.push_back(j+1);
                r[j]=true;
                r_diagonal[i+j]=true;
                l_diagonal[j-i+n]=true;
                if(canwesolve(b,v,n,r,r_diagonal,l_diagonal,i+1))
                    return true;
                else
                {
                    r[j]=false;
                    r_diagonal[i+j]=false;
                    l_diagonal[j-i+n]=false;
                    v.pop_back();
                }
            }
        }
        return false;
    }


    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> b;
        vector<int> v;
        // bitset<n> c;
        // bitset<n> r;
        // bitset<2*n> r_diagonal;
        // bitset<2*n> l_diagonal;
        bool r[n]={0};
        bool r_diagonal[2*n]={0};
        bool l_diagonal[2*n]={0};
        canwesolve(b,v,n,r,r_diagonal,l_diagonal,0);
        return b;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends