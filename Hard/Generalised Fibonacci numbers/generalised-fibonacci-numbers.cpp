//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    vector<vector<long long>> multiply(const vector<vector<long long>>& a, const vector<vector<long long>>& b, long long m) {
        int size = a.size();
        
        vector<vector<long long>> product(size, vector<long long>(size, 0));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; ++j) {
                for (int k = 0; k < size; k++) {
                    product[i][j] += a[i][k] * b[k][j];
                    product[i][j] %= m;
                }
            }
        }
        return product;
    }

public:
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        if (n <= 2) return 1LL % m;
        
        vector<vector<long long>> mat = {{a, b, 1}, {1, 0, 0}, {0, 0, 1}};
        vector<vector<long long>> ans = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        n -= 2;
        while (n > 0) {
            if (n & 1) {
                ans = multiply(ans, mat, m);
            }
            
            mat = multiply(mat, mat, m);
            n = n / 2;
        }
        return (ans[0][0] + ans[0][1] + c * ans[0][2]) % m;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    }
    return 0;
}
// } Driver Code Ends