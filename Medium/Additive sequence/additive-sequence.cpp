//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool isAdditiveSequence(string n) {
        int m = n.size();
        string a,b;
        
        for(int i = 0;i < min(8, m); i++) {
            a += n[i];
            b.clear();
            
            for(int j = i + 1;j < min(i + 8, m - 1); j++) {
                b += n[j];
                int temp1 = stoi(a);
                int temp2 = stoi(b);
                string final;
                final += a; 
                final += b;
                while(final.size() < m){
                    int k = temp1 + temp2;
                    string curr = to_string(k);
                    final += curr;
                    temp1 = temp2;
                    temp2 = k;
                }
                
                if(final == n) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends