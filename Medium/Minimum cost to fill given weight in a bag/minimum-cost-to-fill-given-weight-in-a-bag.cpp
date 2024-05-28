//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
        vector<int> dp (w + 1, INT_MAX);
        dp[0] = 0;
        
        for(int weight = 1; weight <= n; weight++) {
            for(int max_weight = 1; max_weight <= w; max_weight++) {
                if(weight <= max_weight && cost[weight-1] != -1 && dp[max_weight - weight] != INT_MAX)
                    dp[max_weight] = min(dp[max_weight], cost[weight-1] + dp[max_weight - weight]);
            }
        }
        
        return dp[w] == INT_MAX ? -1 : dp[w];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends