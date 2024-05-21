//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        
        vector<int> ans;
        int i = 0, j = 0;
        
        if (arr[index] == x) {
            i = index - 1;
            j = index + 1;
        }
        
        else {
            i = index - 1;
            j = index;
        }
    
        while (k--) {
            if (i < 0) ans.push_back(arr[j++]);
            
            else if (j > n - 1) ans.push_back(arr[i--]);
            
            else if(arr[j] - x <= x - arr[i]) ans.push_back(arr[j++]);
            
            else ans.push_back(arr[i--]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends