//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int i=0, start=0;
       int sum=0;
       while(start<n)
       {
           int i=start;
            do
            {
                sum+=p[i].petrol;
                sum-=p[i].distance;
                if(sum<0)
                {
                    if(i<start)
                        start++;
                    else
                        start=i+1;
                    sum=0;
                    
                    break;
                };
                i++;
                i%=n;
            }while(start!=i);
            if(start==i)
                return i;
       }
       return -1;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends