//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        vector<int> freq (26, 0);
        for (auto ch: s) freq[ch - 'a']++;
        
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            
            int pos = i + 1;
            if (pos % 2 == freq[i] % 2) sum++;
        }
        
        return (sum % 2) ? "ODD" : "EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends