//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
      long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        
        // Create a vector to store the absolute differences and the corresponding indices
        vector<pair<int, int>> diff;

        // Populate the diff vector with pairs of (absolute difference, index)
        for (int i = 0; i < n; ++i)
            diff.push_back({abs(arr[i] - brr[i]), i});

        // Sort the diff vector in descending order based on the absolute differences
        sort(diff.begin(), diff.end(), greater<pair<int, int>>());

        long long tot = 0; // Initialize the total tip amount

        // Iterate over the sorted diff vector
        for (int i = 0; i < n; ++i) {
            int idx = diff[i].second; // Get the original index of the difference

            // Determine whether to choose arr[idx] or brr[idx] for maximizing the tip
            if ((arr[idx] >= brr[idx] && x > 0) || y == 0) {
                tot += arr[idx]; // Add the tip from arr
                --x; // Decrement the count for x
            } else {
                tot += brr[idx]; // Add the tip from brr
                --y; // Decrement the count for y
            }
        }

        return tot; // Return the total maximum tip
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

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends