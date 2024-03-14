//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        vector<vector<int>> vertical(n, vector<int>(n, 0));
        vector<vector<int>> horizontal(n, vector<int>(n, 0));
        int largest_side = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(a[i][j] == 'X') {
                    vertical[i][j] = (i == 0) ? 1 : vertical[i - 1][j] + 1;
                    horizontal[i][j] = (j == 0) ? 1 : horizontal[i][j - 1] + 1;
                }
            }
        }
        
        for (int i = n - 1 ; i >= 0 ; i--) {
            for (int j = n - 1 ; j >= 0 ; j--) {
                int value = min(vertical[i][j], horizontal[i][j]);
                while(value > largest_side) {
                    if(vertical[i][j - value + 1] >= value && horizontal[i - value + 1][j] >= value) {
                        largest_side = value;
                    }
                    
                    value--;
                }
            }
        }
        
        return largest_side;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends