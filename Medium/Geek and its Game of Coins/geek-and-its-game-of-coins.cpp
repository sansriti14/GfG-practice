//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int solve(int n, int x, int y, vector<int>& dp) {
        if (n <= 0) return 0;
        if (dp[n] != -1) return dp[n];
        
        int a = 0, b = 0, c = 0;
        if (n >= 1) {
            a = !solve(n - 1, x, y, dp);
        }
        
        if (n >= x) {
            b = !solve(n - x, x, y, dp);
        }
        
        if (n >= y) {
            c = !solve(n - y, x, y, dp);
        }
        
        if (a || b || c) return dp[n] = 1;
        
        return dp[n] = 0;
    }
    
  public:
    int findWinner(int n, int x, int y) {
        vector<int> dp (n + 1, -1);
        return solve(n, x, y, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends