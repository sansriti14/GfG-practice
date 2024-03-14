//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int nums[], int n, int k)
    {
        unordered_map<int, int> m;
        int ans = 0;
        int preSum = 0;
        for (int i = 0; i < n; i++) {
            preSum += nums[i];
            if(preSum == k)
                ans++;
            
            if(m.find(preSum - k) != m.end()) {
                ans += m[preSum - k];
            }
            
            m[preSum]++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends