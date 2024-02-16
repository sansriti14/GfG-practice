//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        int min_operations = 0;
        priority_queue<int, vector<int>, greater<int>> pq (arr, arr + n);
        
        while(pq.size() > 1) {
            int ele1 = pq.top();
            if(ele1 >= k) return min_operations;
            pq.pop();
            
            int ele2 = pq.top();
            pq.pop();
            
            pq.push(ele1 + ele2);
            min_operations++;
        }
        
        if(pq.empty()) return -1;
        return (pq.top() >= k) ? min_operations : -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends