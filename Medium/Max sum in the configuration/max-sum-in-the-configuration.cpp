//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        long long initialSum = 0;
        long long total = 0;
        
        for (int i = 0; i < n; i++) {
            initialSum += a[i];
            total += (long long)(i)*a[i];
        }
        
        long long maxSum = total;
        for (int i = 1; i < n; i++) {
            total = total + initialSum - long(n) * a[n - i];
            if (total > maxSum) {
                maxSum = total;
            }
        }
        return maxSum;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends