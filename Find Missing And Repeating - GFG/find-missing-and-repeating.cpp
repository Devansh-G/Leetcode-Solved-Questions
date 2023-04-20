//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans = new int[2];
        ans[0] = ans[1] = -1;
        int num1=0, num2=0, sum=0, Xor=0, expected_sum=0, expected_xor=0;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++)
        {
            expected_sum+=(i+1);
            sum+=arr[i];
            Xor^=arr[i];
            expected_xor^=(i+1);
        }
        int reqd_xor = Xor ^ expected_xor;      //xor of 2 numbers
        //cout<<reqd_xor<<endl;
        for(int i=0;i<n;i++)
        {
            int temp= reqd_xor ^ arr[i];
            if(temp <=0 || temp>n)
                continue;
            if(sum + temp - arr[i] == expected_sum)
            {
                if(map[temp]==arr[i])
                {
                    ans[0]=arr[i];
                    ans[1]=temp;
                    //cout<<i<<endl;
                    break;
                }
                map[temp]=arr[i];
            }
            // else if(sum + arr[i] - temp == expected_sum)
            // {
            //     if(map[arr[i]]==temp)
            //     {
            //         ans[0]=arr[i];
            //         ans[1]=temp;
            //         cout<<i<<endl;
            //         break;
            //     }
            //     map[arr[i]]=temp;
            // }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends