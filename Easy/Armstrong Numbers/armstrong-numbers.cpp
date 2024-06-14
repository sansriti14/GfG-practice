//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n)
    {
        int ans = 0;
        int num = n;
        while (n != 0)
        {
            int rem = n % 10;
            ans += rem * rem * rem;
            n /= 10;
        }
        
        return (ans == num) ? "true" : "false";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends