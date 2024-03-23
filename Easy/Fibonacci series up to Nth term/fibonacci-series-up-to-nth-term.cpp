//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        vector<int> ans = {0, 1};
        int mod = 1e9 + 7;
        
        int a = 0, b = 1;
        
        for(int i = 0; i < n - 1; i++) {
            int c = (a + b) % mod;
            ans.push_back(c % mod);
            a = b;
            b = c;
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
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends