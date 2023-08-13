//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int setBit(int n)
    {
        int ans = 0;
        while(n>0 and (n&1) == 0)
        {
            ans++;
            n = n>>1;
        }
        return ans;
    }
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        if(nums.size()== 2)
            return nums;
            
        int num1 =0, num2 =0, Xor = 0;
        for(int i = 0;i<nums.size();i++)
            Xor^=nums[i];
            
        int last = setBit(Xor);
    
        for(int i =0; i<nums.size() ; i++)
        {
            if(nums[i] & (1<<last))
                num1^=nums[i];
            else
                num2^=nums[i];
        }
        vector<int> v;
        if(num1 > num2)
            swap(num1, num2);
        v.push_back(num1);
        v.push_back(num2);
        return v;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends