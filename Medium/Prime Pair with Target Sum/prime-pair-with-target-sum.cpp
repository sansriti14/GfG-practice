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
    vector<int> getPrimes(int n) {
        vector<bool> storePrime (n + 1, true);
        for (int i = 2; i * i <= n; i++) {
            for (int j = i * i; j < n; j += i) {
                storePrime[j] = false;
            }
        }
        
        storePrime[0] = false;
        storePrime[1] = false;
        
        for (int i = 2; i <= n; i++) {
            if (storePrime[i] && storePrime[n - i]) {
                return {i, n - i};
            }
        }
        
        return {-1, -1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends