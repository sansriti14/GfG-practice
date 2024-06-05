//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        int sum_a = accumulate(a, a + n, 0);
        int sum_b = accumulate(b, b + m, 0);
        
        int difference = sum_a - sum_b;
        
        if (difference & 1) return -1;
        
        unordered_set<int> st(a, a + n);
        for (int i = 0; i < m; i++) {
            if (st.find(b[i] + (difference / 2)) != st.end()) return 1;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends