//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int findMinOperations(int prevIndex, int currIndex, vector<int>& nums, vector<vector<int>>& dp) {
        if (currIndex >= nums.size()) return 0;
        if (dp[prevIndex + 1][currIndex] != -1) return dp[prevIndex + 1][currIndex];
        
        int numOperations = findMinOperations(prevIndex, currIndex + 1, nums, dp);
        if (prevIndex == -1 || (nums[currIndex] > nums[prevIndex] && nums[currIndex] - nums[prevIndex] >= currIndex - prevIndex)) {
            numOperations = max(numOperations, 1 + findMinOperations(currIndex, currIndex + 1, nums, dp));
        }
        
        return dp[prevIndex + 1][currIndex] = numOperations;
    }
    
  public:
    int min_operations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        vector<vector<int>> dp (n + 2, vector<int> (n + 1, -1));
        return n - findMinOperations(-1, 0, nums, dp);;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends