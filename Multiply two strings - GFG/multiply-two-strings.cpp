//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
            
       int l1=s1.length(), l2=s2.length();
       string s;
       for(int i=0;i<l1+l2;i++)
            s+='0';
      if((l1==1 &&s1[0]=='0') || (l2==1 &&s2[0]=='0'))
        return "0";
      
      int flag1=0,flag2=0;
       if(s1[0]=='-')
            flag1=1;
        if(s2[0]=='-')
            flag2=1;
            
        int no=0,carry=0,index=0;
        l2--;
        l1--;
       while(l2>=flag2)
       {
           int i=l1;
           while(i>=flag1)
           {
               no=((s1[i]-'0')*(s2[l2]-'0')) + carry;
               carry=no/10;
               no%=10;
               index=s2.length()-l2+s1.length()-i -2;
               s[index]+=no;
               carry+=((s[index]-'0')/10);
               s[index]=(s[index]-'0')%10;
               s[index]+='0';
               i--;
           }
           while(carry)
           {
               index++;
               s[index]+=carry;
               carry=(s[index]-'0')/10;
               s[index]=((s[index]-'0')%10);
               s[index]+='0';
           }
            l2--;
       }
       index=s1.length() + s2.length() - 1;
       while(s[index]=='0')
        {
            s.pop_back();
            index--;
        }
        
        if((flag1+flag2)%2)
            s.push_back('-');
        reverse(s.begin(),s.end());
        return s;
    }
};


//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends