//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
     string longestSubstring(string s, int n) {
        if(n == 1) return "-1";
        
        int max_length = 0;
        string ans = "-1";
        
        int i =0, j = 0;
        while(j < n) {
            string str = s.substr(i, j - i + 1);
            
            if(s.find(str, j + 1) != string::npos){
                if(j - i + 1 > max_length){
                    max_length = j - i + 1;
                    ans = str;
                }
                
                j++;
            }
            else i++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends